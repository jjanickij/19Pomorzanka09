#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll M = 1e5;
ll n, k, a[M+5];
bool odw[M+5];
vector<ll> graf[M+5];
ll wynik,X,Y;

void dfs(ll v){
	odw[v]=true;
	vector<ll> synowie;
	for(auto u : graf[v]){
		if(odw[u])
			continue;
		dfs(u);
		synowie.push_back()
}
sort
}


int main(){
  cin >> n >> k;
	for(ll i=1; i<=n; i++)
    cin >> a[i];
	for(ll i=0; i<n-1; i++){
		cin >> X >> Y;
		graf[X].push_back(Y);
		graf[Y].push_back(X);
	}
	dfs(1, -1);
	cout << wynik << endl;
}
