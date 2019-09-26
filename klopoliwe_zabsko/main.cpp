#include <bits/stdc++.h>
using namespace std;

const short maxn = 5001;
short h, w, n;
pair<short, short>  pt[maxn];
short dp[maxn][maxn];
map<pair<short, short> , short> T;

bool cmp(pair<short, short>  a, pair<short, short>  b)
{
	if (a.first != b.first) return a.first > b.first;
	return a.second > b.second;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> h >> w >> n;
	for (short i = 1; i <= n; i++)
		cin >> pt[i].first >> pt[i].second;
	sort(pt+1, pt+n+1, cmp);
	for (short i = 1; i <= n; i++)
		T[pt[i]] = i;
	short odp = 0;
	for (short i = 1; i <= n; i++)
	{
		for (short j = i-1; j >= 1; j--)
		{
			short a = pt[j].first-pt[i].first, b = pt[j].second-pt[i].second;
			short l;
			short x = 0;
			if (T.find({pt[j].first+a, pt[j].second+b}) == T.end())
			{
				if (pt[j].first+a > h || pt[j].first+a < 1 || pt[j].second+b > w || pt[j].second+b < 1)
					x = 1;
			}
			else
			{
				l = T[{pt[j].first+a, pt[j].second+b}];
				x = dp[j][l];
			}
			if (x != 0)
			{
				dp[i][j] = x+1;
				if (pt[i].first-a > h || pt[i].first-a < 1 || pt[i].second-b > w || pt[i].second-b < 1)
					odp = max(odp, dp[i][j]);
			}
		}
	}

	if (odp >= 3)
		cout << odp << endl;
	else
		cout << 0 << endl;
		return 0;
}
