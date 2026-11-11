#include<bits/stdc++.h>
#define N 501000
#define M 301000
using namespace std;
int n,m;
int a[N],edge[N],ans[N],edges[N];
vector<int> b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].push_back(i);
		edge[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(edges,0,sizeof edges);
		edge[a[i-1]]--;
		for(int j=i;j<=n;j++){
			int flag=1;
			if(edge[a[j]]>=1){
				for(auto c:b[a[j]]){
					if(c>j){
						j=c-1;
						flag=0;
					}
				}
			}
			if(flag&&!edges[a[j]]){
				ans[a[j]]++;
				edges[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
