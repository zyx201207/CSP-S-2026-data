#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,T,n,d,x[2000005],sum,ans,minn;
void dfs(int u,int v,int dep){
	if(dep>minn)return ;
	if(u==v&&dep==minn){
		sum++;return ;
	}
	for(int i=u+1;i<=v;i++){
		if(x[i]-x[u]<=d)dfs(i,v,dep+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int u=1;u<n;u++){
			for(int v=u+1;v<=n;v++){
				int now=u,ff=0;minn=sum=0;
				while(now!=v){
					int f=0;
					for(int p=v;p>now;p--){
						if(x[p]-x[now]<=d){
							f=1;now=p;minn++;break;
						}
					}if(!f){
						ff=1;break;
					}
				}
				if(ff||x[v]-x[u]<=d)continue;
				dfs(u,v,0);
				if(sum==2)ans++;
			}
		}cout<<ans<<"\n";
	}//17:30 8pts
	return 0;
}
//16:59 eat another chocolate
//yi yan DP,dan shi bu hui
//mei jiu le
//guess:blue
//rp++,zhu wo 1=!!!
