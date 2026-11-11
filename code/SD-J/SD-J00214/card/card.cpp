#include <bits/stdc++.h>
using namespace std;
const int N=5e5+50,M=3e5+50;
int n,m;
int a[N],vis[M],cnt[M];
deque <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(!vis[x]){
				vis[x]=1;
				q.push_back(x);
			}else{
				while(!q.empty()&&q.back()!=x){
					vis[q.back()]=0;
					q.pop_back();
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(vis[i]) cnt[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
