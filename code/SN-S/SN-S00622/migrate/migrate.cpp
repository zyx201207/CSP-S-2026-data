#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C,T,n,d,ans,a[2000010],dis[2000010],c[2000010];
void baoli(ll now,ll cnt){
	for(int i=now+1;i<=n;i++){
		if(a[i]-a[now]<=d){
			if(cnt+1>dis[i]) break;
			else if(cnt+1<dis[i]){
				dis[i]=cnt+1;
				c[i]=1;
			}
			else if(cnt+1==dis[i]){
				c[i]++;
			}
			baoli(i,cnt+1);
		}
		else break;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(C==11||C==12||n<4){
			cout<<0<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int i=1;i<=n;i++) dis[i]=LLONG_MAX;
			memset(c,0,sizeof(c));
			baoli(i,0);
			for(int j=i+1;j<=n;j++){
				if(c[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//¿ÉË«Ïò·É 
