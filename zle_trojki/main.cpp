#include <bits/stdc++.h>
using namespace std;

const int M = 5e5+1;
int n,m;
int a,b;
int temp;
vector<int> graf[M];
bool odw[M];
vector<int> wyn;
set<int> matrix[M];
vector<int> pomoc;
bool czy_cykl()
{
    int licznik=2;
    for(int i=1; i<=n; i++)
    {
        if(licznik != graf[i].size()) return 0;
    }
    return 1;
}

int aa,bb,cc;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        cin >> a >> b;
        pomoc.push_back(a);
        graf[a].push_back(b);
        graf[b].push_back(a);
        matrix[a].insert(b);
        matrix[b].insert(a);
    }

    if(n>m){ cout << -1; return 0;}

    else if(czy_cykl())
    {
        if(n%3!=0) {cout << -1;return 0;}
        else
        {
            temp=n/3;
            cout << pomoc[0] << " " << pomoc[temp] << " " << pomoc[temp+temp];
            return 0;
        }

    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(graf[i].size()>=3)
            {
                aa=graf[i][0];
                bb=graf[i][1];
                cc=graf[i][2];
                //cout << aa << "#" << bb << "#" << cc;
                if(matrix[bb].find(aa) != matrix[bb].end()) {cout << bb <<" "<< aa << " " << i;return 0;}
                else if(matrix[bb].find(cc) != matrix[bb].end()) {cout << bb <<" "<< cc << " " << i;return 0;}
                else if(matrix[cc].find(aa) != matrix[cc].end()) {cout << cc <<" "<< aa << " " << i;return 0;}
                else if(matrix[bb].find(aa) != matrix[bb].end() && matrix[bb].find(cc) != matrix[bb].end() && matrix[cc].find(aa) != matrix[cc].end()) {cout << cc <<" "<< aa << " " << i;return 0;}
                else {cout << aa << " " << bb << " " << cc; return 0;}
            }
        }
    }
    cout << -1;
    return 0;
}
