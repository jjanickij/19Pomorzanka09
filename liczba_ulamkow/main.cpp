#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;
unsigned long long phi[M+7];

void generatePhi() {
    phi[1] = 0;
    for (int i = 2; i <= M; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for(int j = (i << 1); j <= M; j += i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j] * (i-1) / i;
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(0);
	int z;
	cin >> z;
	generatePhi();
	while(z--)
    {
        int n,m;
        cin >> n >> m;
        long long wynik = 0;
        for(int i=2; i<=m; i++)
        {
            wynik+=(n/i) * phi[i];
        }
        wynik*=2;
        wynik+=n;
        cout<< wynik << endl;
    }

	return 0;
}
