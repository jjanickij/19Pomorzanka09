#include <bits/stdc++.h>
using namespace std;

int n,tab[4];
int min_id;
char kod_wyn;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> kod_wyn;
        if(kod_wyn == 'A')
            tab[0]++;
        else if(kod_wyn == 'C')
            tab[1]++;
        else if(kod_wyn == 'G')
            tab[2]++;
        else if(kod_wyn == 'T')
            tab[3]++;
    }

//    for(int i=0; i<4; i++)
//        cout << tab[i] << " "; // ile jest kazdej literki - debug

    for (int i = 1; i < 4; i++)
    {
        if (tab[i] < tab[min_id])
        {
            min_id = i;
        }
    }

    switch (min_id)
    {
    case 0:
        kod_wyn = 'A';
        break;
    case 1:
        kod_wyn = 'C';
        break;
    case 2:
        kod_wyn = 'G';
        break;
    case 3:
        kod_wyn = 'T';
        break;
    }

    cout << tab[min_id] << endl;

    for (int i = 0; i < n; i++)
    {
        cout << kod_wyn;
    }

    return 0;
}


