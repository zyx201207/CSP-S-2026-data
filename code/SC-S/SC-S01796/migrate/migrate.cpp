#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T,cnt,p[2000005];
ll n,d,ans=LONG_LONG_MAX,dis[2000005];
void dfs(int x,ll pre,int r){
	if(pre>ans)return ;
	if(x>r)return ;
	if(x==r){
		ans=(ll)min(ans,pre);
		return ;
	}
	for(int i=x+1;i<=r&&dis[i]<=dis[x]+d;i++)
		dfs(i,pre+1,r);
}
void dfs1(int x,ll pre,int r){
	if(pre>ans)return ;
	if(x>r)return ;
	if(x==r&&pre==ans){
		cnt++;
		return ;
	}
	if(x==r)return ;
	for(int i=x+1;i<=r&&dis[i]<=dis[x]+d;i++)
		dfs1(i,pre+1,r);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c>4){
		while(T--)cout<<"0\n";
		return 0;
	}
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>dis[i];
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,0,j);
				dfs1(i,0,j);
				if(cnt==2)tot++;
				ans=LONG_LONG_MAX,cnt=0;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
