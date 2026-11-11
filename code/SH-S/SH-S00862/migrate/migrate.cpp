#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2001000],k,tmp,aans,ans;
void dfs(int dep,int from,int to,int now){
	if(dep>tmp){
		return ;
	}
	if(now>=to&&dep==tmp){
		aans++;
		return ;
	}
	for(int i=now+1;a[i]-a[now]<=d&&i<=to;i++){
		dfs(dep+1,from,to,i);
	}
}
void solve(){
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		int gcx=a[2]-a[1];
		int num=d/gcx;
		if(num<2){
			puts("0");
			continue;
		}
		int nnum=num*2-1;
		printf("%lld\n",max(n-nnum,0ll));
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	if(c==11||c==12){
		solve();
		return 0;
	}
	while(t--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				k=i,tmp=0,aans=0;
				bool flag=true;
				while(a[j]-a[k]>d){
					int u=k;
					if(a[k+1]-a[k]>d){
						flag=false;
						break;
					}
					while(a[u+1]-a[k]<=d){
						u++;
					}
					k=u;
					tmp++;
				}
				if(!flag)continue;
				tmp++;
				dfs(0,i,j,i);
				if(aans==2){
					ans++;
				}
				//cout<<i<<" "<<j<<" "<<ans<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
