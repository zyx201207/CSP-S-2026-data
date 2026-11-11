#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n, m;
int a[N];
vector<int> b;
struct Node{
	bool vis;
	int des;
}tick[N];
int sum[N], idx;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		b.clear();
		idx = 0;
		for(int j = 1; j <= m; j++) tick[j].des = tick[j].vis = 0;
		for(int j = i; j <= n; j++){
			if(!tick[a[j]].vis){
				b.push_back(a[j]);
				tick[a[j]].vis = 1;
				tick[a[j]].des = idx++;
			}
			else{
				int t = idx;
				for(int k = tick[a[j]].des; k < t; k++){
					tick[b.back()].vis = 0;
					tick[b.back()].des = -1;
					b.pop_back();
					idx--;
				}
				b.push_back(a[j]);
				tick[a[j]].vis = 1;
				tick[a[j]].des = idx++;
			}
		}
		for(int j = 0; j < b.size(); j++){
			sum[b[j]]++;
		}
	}
	for(int i = 1; i <= m; i++) printf("%d ", sum[i]);
	return 0;
}

