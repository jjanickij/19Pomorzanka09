#include <bits/stdc++.h>
using namespace std;

const int dod = 30001;

vector <int> v[60005];
set <pair<int,int>> temp;

bool cmp(pair <int,int> a, pair<int,int> b){
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
vector <pair<int,int>> zdarzenia;

const int leaf = 1 << 16;

int tree[leaf*2+5];
int lazy[leaf*2+5];

void add(int x, int v){
	lazy[x] += v;
	tree[x] += v;
}
void push(int x){
	add(x*2, lazy[x]);
	add(x*2+1, lazy[x]);
	lazy[x] = 0;
}

void insert(int gdzie, int pocz, int kon, int x, int y, int v){
	if (pocz >= x && kon <= y){
		add(gdzie, v);
		return;
	}
	push(gdzie);
	int sr = (pocz+kon) / 2;
	if (x <= sr)
		insert(2*gdzie, pocz, sr, x, y, v);
	if (y > sr)
		insert(2*gdzie+1, sr+1, kon, x, y, v);
	tree[gdzie] = max(tree[gdzie*2], tree[gdzie*2+1]);
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int s, w;
	cin >> s >> w;
	int n;
	cin >> n;
	int x, y;
	for (int i = 1; i <= n; ++i){
		cin >> x >> y;
		x += dod;
		y += dod;
		temp.insert({x, 1});
		temp.insert({x+s,2});
		v[x].push_back(y);
	}
	for (auto u: temp)
		zdarzenia.push_back(u);
	sort(zdarzenia.begin(),zdarzenia.end(), cmp);

	int MAX_wyn = 0;
	for (auto u: zdarzenia){
		if (u.second == 1){
			//cout << "Add: " << u.first-dod << "\n";
			for (auto i: v[u.first]){
				//cout << i-dod << " ";
				insert(1, 1, leaf, i-w, i, 1);
			}
			int wynik = tree[1];
			//cout << "\nwynik: " << wynik << "\n";
			MAX_wyn = max(MAX_wyn, wynik);
		}
		else{
			//cout << "Delete: " << u.first-s-dod << "\n";
			for (auto i: v[u.first-s]){
				//cout << i-dod << " ";
				insert(1, 1, leaf, i-w, i, -1);
			}
			//cout << "\n";
		}
	}

	cout << MAX_wyn << "\n";
  return 0;
}
