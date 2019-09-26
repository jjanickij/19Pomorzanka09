#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e6;
int n;
ll x, pref[M+5];
ll p, w;

int main ()
{
	ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> x;
		pref[i]=pref[i-1]+x;
	}
	cin >> p;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<=min(i-1,n-i); j++)
			if((pref[i+j]-pref[i-j-1])/(2*j+1)>=p)
				w++;

		for(int j=0; j<=min(i-1,n-i-1); j++)
			if((pref[i+j+1]-pref[i-j-1])/(2*j+2)>=p)
				w++;
	}
	cout << w;
  return 0;
}
