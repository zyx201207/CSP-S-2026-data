#include <bits/stdc++.h>
using namespace std;

long long n,m,clist[1000000],cond[1000000];
bool vis[10000000];
queue<int> q;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 0;i < n;++i){
		cin >> clist[i];
	}
	for(long long i = 0;i < n;++i){
		for(long long j = i;j < n;++j){
			long long k = clist[j];
			if(vis[k] == 1){
				while(!q.empty()){
					vis[q.front()] = 0;
					q.pop();
				}
			}
			vis[k] = 1;
			q.push(k);
		}
		while(!q.empty()){
			vis[q.front()] = 0;
			cond[q.front()] += 1;
			q.pop();
		}
	}
	for(long long i = 1;i <= m;++i){
		cout << cond[i] << " ";
	}
} 
