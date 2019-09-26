#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll next2 (ll x)
{
    ll counter=0;
    while ( x > 0 )
    {
        counter++;
        x=x>>1;
    }
    return (1<<counter);
}
ll maks;
const ll M = 1e5;
ll n,q,t[M+1];
struct Q{
    ll a;
    ll b;
    ll mod;
    ll id;
    ll wynik;
};

bool cmp(Q a, Q b){
    return a.mod < b.mod;
}

bool revcmp(Q a, Q b){
    return a.id < b.id;
}

Q zap[M+1];
ll R;
ll iloczyn(ll x, ll y, ll modzik, ll tree[])
{
    x+=R-1;
    y+=R-1;
    ll wyn=tree[x];
    if(x!=y)
    {
        wyn*=tree[y];
        wyn%=modzik;
    }
    while(x/2 != y/2)
    {
        if(x%2==0)
        {
            wyn*=tree[x+1]%modzik;
            wyn%=modzik;
        }
        if(y%2==1)
        {
            wyn*=tree[y-1]%modzik;
            wyn%=modzik;
        }
        x/=2;
        y/=2;
    }
    return (wyn%modzik);
}

int main()
{
    cin >> n >> q;
    R=next2(n);
    //cout << R;
    ll tree[2*R];
    ll r2=2*R;
    fill(tree,tree+r2,1);
    for(ll i=0; i<n; i++)
    {
        cin >> t[i];
        tree[i+R]=t[i];
    }

    for(ll i=0; i<q; i++)
    {
        cin >> zap[i].a >> zap[i].b >> zap[i].mod;
        zap[i].id=i;
    }

    sort(zap, zap+q, cmp);

    for(ll i=0; i<q; i++)
    {
        if(zap[i].mod>maks)
        {
            for(ll j=R-1; j>=1; j--)
            {
                tree[j]=((tree[j*2])%zap[i].mod)*((tree[j*2+1])%zap[i].mod);
                tree[j]%=zap[i].mod;
            }
            maks=zap[i].mod;
        }
        zap[i].wynik=iloczyn(zap[i].a, zap[i].b, zap[i].mod, tree);
//        for(ll j=R; j<2*R; j++)
//            cout << tree[j] << " ";
    }

    sort(zap, zap+q, revcmp);
    for(ll i=0; i<q; i++)
        cout << zap[i].wynik << endl;

    return 0;
}

