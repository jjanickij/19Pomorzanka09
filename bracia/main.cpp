#include <bits/stdc++.h>
using namespace std;

const int M = 1e6;
int n,l[M+5],poc[M+5],kon[M+5],score[M+5];

int main()
{
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    cin >> l[i];
    if(poc[l[i]] == 0)
      poc[l[i]]=i;
    kon[l[i]]=i;
  }

  for(int i=1; i<=n; i++)
  {
    score[i]=score[i-1];
    if(kon[l[i]] == i)
      score[i]=max(score[i], score[poc[l[i]]-1]+1);
  }

  cout << score[n];

  return 0;
}
