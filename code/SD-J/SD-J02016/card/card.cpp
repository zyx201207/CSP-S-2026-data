#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],num[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		deque<int> q;
		memset(vis,0,sizeof(vis));
		for (int j=i;j<=n;j++){
			q.push_back(a[j]);
			++vis[a[j]];
			if (!q.empty()&&vis[a[j]]==2){
				while (!q.empty()&&vis[a[j]]!=0){
					if (q.back()==a[j]){
						--vis[a[j]];
					}
					q.pop_back(); 
				}
				++vis[a[j]];
				q.push_back(a[j]);
			}
		}
		while (!q.empty()){
			num[q.front()]++;
			q.pop_front();
		}
	}
	for (int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
