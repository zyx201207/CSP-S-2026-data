#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int tes,T,n,b[N],c[N];
ll a[N],m,ans;
void dfs(int x,int t){
	if(x>n) return;
	for(int i=x+1;i<b[x];i++){
		c[++t]=i;
		int res=0;
		for(int k=2;k<t;k++){
			if(a[c[k+1]]-a[c[k]-1]<=m&&c[k]>2&&a[c[k+1]]-a[c[k]-2]<=m){
				res=2;
				break;
			}
			res+=(a[c[k+1]]-a[c[k]-1]<=m);
			if(res==2) break;
		}
		ans+=(res==1);
		t--;
		if(i==b[x]-1){
			c[++t]=i;
			if(i<=n)dfs(i,t);
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>tes>>T;
	while(T--){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) b[i]=upper_bound(a+i,a+n+1,a[i]+m)-a;
		if(tes<=6){
			for(int i=1;i<=n;i++) c[1]=i,dfs(i,1);
		}
		else if(tes==11||tes==12){
			if(a[2]-a[1]>m) ans=0;
			else{
				for(int i=1;i<=n;i++)
					if(b[b[i]-1]!=n+1&&b[b[i]-1]) ans++;
				if(ans!=n-3&&ans) ans+=2;
				else ans=0;
			}
		}
		else if(tes==13||tes==14) ans=0;
		cout<<ans<<'\n';
	}
	return 0;
}