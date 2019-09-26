#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct wartosci
{
    int use;
    ll ilosc;
    vector<int> zb;
};

ll check(ll a)
{
    if (a < 0)
        return -1 * a;
    return a;
}

int n;
ll suma_pom = 0, need;
int p1, p2;
queue<int> kolejka;
stack<int> stos;
int pom;

int main()
{

    cin >> n;
    wartosci tab[n+1];
    for (int i = 1; i <= n; i++)
    {
        cin >> tab[i].ilosc;
        suma_pom += tab[i].ilosc;
    }
    need = suma_pom / n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> p1 >> p2;
        tab[p1].zb.push_back(p2);
        tab[p2].zb.push_back(p1);
    }
    tab[1].use = 0;
    kolejka.push(1);
    stos.push(1);
    while (!kolejka.empty())
    {
        pom = kolejka.front();
        kolejka.pop();
        for (int i = 0; i < tab[pom].zb.size(); i++)
            if (tab[pom].use != tab[pom].zb[i])
            {
                tab[tab[pom].zb[i]].use = pom;
                kolejka.push(tab[pom].zb[i]);
                stos.push(tab[pom].zb[i]);
            }
        tab[pom].zb.clear();
    }
    ll wynik_kon = 0;
    while (!stos.empty())
    {
        pom = stos.top();
        stos.pop();
        tab[tab[pom].use].ilosc += tab[pom].ilosc - need;
        wynik_kon += check(tab[pom].ilosc - need);
        tab[pom].ilosc = need;
    }
    cout << wynik_kon;
    return 0;
}
