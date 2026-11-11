#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
ll x[N],d;
int cnt[N];
int c,n;
void dfs(int u,int de,int g){
	if(u==g){
		cnt[de]++;
		return;
	}
	for(int i=u+1;i<=n;i++){
		if(x[i]-x[u]<=d)dfs(i,de+1,g);
	}
	return;
}
void solve(){
	scanf("%d%lld",&n,&d);
	int ans=0;
	for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=0;k<=n;k++)cnt[k]=0;
			dfs(i,0,j);
			for(int k=0;k<=n;k++){
				if(cnt[k]){
//					cout<<cnt[k]<<endl;
					if(cnt[k]==2)ans++;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	scanf("%d%d",&c,&t);
	while(t--){
		solve(); 
	}
	return 0;
}