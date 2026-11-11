#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,m,s,ans,a[2000010],f[2000010];
void dfs(int now,int x,int bs){
	if(bs==x){
		f[now]++;return ;
	}
	if(now>n)return ;
	for(int i=now+1;i<=n;i++)
		if(a[i]-a[now]>m)break;
		else dfs(i,x,bs+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=2;i<n;i++)
			if(a[i+1]-a[i]==a[i]-a[i-1])
				s++;
		if(s==n-2)
			if(m/(a[2]-a[1])==2&&n>=4)
				cout<<n-4+1<<"\n";
			else cout<<0<<"\n";
		else{
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++){
					memset(f,0,sizeof(f));
					dfs(i,j,0);
					for(int k=1;k<=n;k++)
						ans+=(f[k]==2);
				}
			cout<<ans<<"\n";
		}
	}
}
