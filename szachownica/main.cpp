#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll pot(ll a)
{
    if(a%2==0)
        return 1;
    else
        return -1;
}
ll f(ll x)
{
    if(x==1) return 0;
    if(x==2) return 1;
    if(x>2) return (((x*f(x-1))%m) + pot(x%m));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    ll q=f(n%m);
    cout << q*q%m;
    return 0;
}
