/*
* Modul de rezolvare al acestui algoritm se bazeaza pe
* gasirea unui caz care nu poate fi intalnit 
* intr-o propozitie.
* 
* Notatiile conectorilor logici in algoritm
* 1. Negatia: !
* 2. Conjunctia: &
* 3. Disjunctia: |
* 4. Implicatia: -
* 5. Echivalenta: =
* 
* Am luat fiecare caracter din expresie si l-am analizat.
* 
* Rationamentul pe care m-am bazat in rezolvare:
* 
* 1.Am tratat cazul particular in care exresia contine un singur caracter
* - Daca acesta este litera , propozitia e corecta, altfel nu
* 
* 2.Primul caracter dintr-o expresie nu poate fi:
* -litera
* -conector logic
* - ')'
* 
* 3.Ultimul caracter dintr-o expresie nu poate fi:
* -litera
* -conector logic
* - '('
* 
* 4.Caracterul '(' nu poate fi urmat de:
* - ')'
* -cojunctie, disjunctie, implicatie , echivalenta (negatia e admisa)
* 
* 5.Caracterul ')' nu poate fi urmat de:
* - '('
* -negatie
* -litera
* 
* 6.Conectorii logici nu pot fi urmati de:
* -conectori logici
* -')'
* 
* 7.Literele nu pot fi urmate de:
* -litere
* -negatie
* - '('
* 
* 8.O alta conditie ca sirul sa fie o propozitie este ca:
* - numarul de paranteze '(' sa fie egal cu numarul de 
* paranteze ')' si cu numarul de conectori logici
* 
* Expresiile din Tema1 au verificat algoritmul:
* (a-True)   (((P-Q)|S)=T)
* (b-False)  ((P-(Q&(S-T))))
* (c-False)  (!(B(!Q))&R)
* (d-True)   (P&((!Q)&(!(!(Q=(!R))))))
* (e-False)  ((P|Q)-!(P|Q))&(P|(!(!Q)))
*/
#include <iostream>
#include<cstring>
using namespace std;
char s[1005];

bool expression()
{
    if (strlen(s) == 1)
    {
        if (isalpha(s[0]))
            return true;
        else
            return false;
    }
    else
    {
        if ((strchr(")!|&-=", s[0]) || isalpha(s[0])) ||
            (strchr("(!|&-=", s[strlen(s) - 1]) || isalpha(s[strlen(s) - 1])) )
            return false;
        int i,nrLeft,nrRight,nrCon;
        nrLeft = nrRight = nrCon = 0;
        for (i = 0; i < strlen(s) - 1; i++)
        {
            if (s[i] == '(')
            {
                nrLeft++;
                if (strchr(")&|-=", s[i + 1]))
                    return false;
            }
            if (strchr("!&|-=", s[i]))
            {
                nrCon++;
                if (strchr(")!&|-=", s[i + 1]))
                    return false;
            }
            if (s[i] == ')')
            {
                nrRight++;
                if (strchr("!(", s[i + 1]) || isalpha(s[i+1]))
                    return false;
            }
            if (isalpha(s[i]))
            {
                if (strchr("!(", s[i + 1]) || isalpha(s[i + 1]))
                    return false;
            }
            
        }
        if (s[strlen(s) - 1] == ')')
            nrRight++;
        if (nrCon != nrLeft || nrCon != nrRight || nrRight != nrLeft)
            return false;

    }
    return true;
}

int main()
{
    cin.get(s,1005);
    if (expression() == true)
        cout << "Este propozitie";
    else
        cout << "Nu este propozitie";
    return 0;
}

