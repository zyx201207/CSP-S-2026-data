#include<bits/stdc++.h>
#define int long long
using namespace std;
long long c,T,ans,d,n,a[2000005],Min,cnt,f[2000005],vis[2000005],ss;
void dfs(long long x,long long lon,long long y){
	if(x==y){
		Min=min(Min,lon);
		cnt++;
		f[cnt]=lon;
		return ;
	}
	if(lon>Min)return ;
	long long i=x+1;
	while(i<=n){
		if(a[i]-a[x]>d)break;
		if(!vis[i]){
			vis[i]=1;
			dfs(i,lon+1,y);
			vis[i]=0;
		}
		i++;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	for(int i=1;i<=T;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ss=0;
		for(int x=1;x<=n;x++){
			for(int y=x+1;y<=n;y++){
				ans=0;
				Min=INT_MAX;
				memset(f,0,sizeof(f));
				cnt=0;
				dfs(x,0,y);
				for(int i=1;i<=cnt;i++){
					if(f[i]==Min)ans++;
				}
				if(ans==2)ss++;
			}
		}
		cout<<ss<<"\n";
	}
	return 0;
}