#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,ans;
int a[N];
int s[31];
bool vis[N];
bool b[N][31];

void dfs(int u){
	if(u==-1)return;
	if(s[u]>=m){
		ans|=(1<<u);
		for(int i=1;i<=n;i++)
			if(!b[i][u]&&vis[i]){
				vis[i]=0;
				for(int j=0;j<u;j++){
					int t=(a[i]>>j)&1;
					s[j]-=t;
				}
			}
	}
	dfs(u-1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<30;j++){
			bool t=(a[i]>>j)&1;
			b[i][j]=t,s[j]+=t;
		}
	}
	for(int i=1;i<=n;i++)vis[i]=1;
	dfs(29);
	cout<<ans;
	return 0;
} 
