#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define db double
#define pii pair<int,int>
const int N=2e6+5;
int f[N],n,T,c;ll g[N],sum[N];
ll dis[N],d,ans,ans1;
void solve(){
	cin>>n>>d;ans=0;
	for(int i=1;i<=n;i++) cin>>dis[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) sum[j]=f[j]=g[j]=0;
		g[i]=1,sum[i]=1;
		for(int j=i+1;j<=n;j++){
			int p=lower_bound(dis+1,dis+n+1,dis[j]-d)-dis;
			p=max(p,i);
			f[j]=f[p]+1;
			int l=p,r=j-1,res=0;
			while(l<=r){
				int mid=((l+r)>>1);
				if(f[mid]==f[p]) res=mid,l=mid+1;
				else r=mid-1;
			}
			g[j]=sum[res]-sum[p-1];
			sum[j]=g[j]+sum[j-1];
			if(g[j]==2) 
				ans++;
		}
	}
	cout<<ans<<"\n";
}
void solve2(){
	cin>>n>>d;ans=ans1=0;
	for(int i=1;i<=n;i++) cin>>dis[i];
	for(int j=1;j<=n;j++) sum[j]=f[j]=g[j]=0;
	g[1]=1,sum[1]=1;
	for(int j=2;j<=n;j++){
		int p=lower_bound(dis+1,dis+n+1,dis[j]-d)-dis;
		p=max(p,1);
		f[j]=f[p]+1;
		int l=p,r=j-1,res=0;
		while(l<=r){
			int mid=((l+r)>>1);
			if(f[mid]==f[p]) res=mid,l=mid+1;
			else r=mid-1;
		}
		g[j]=sum[res]-sum[p-1];
		sum[j]=g[j]+sum[j-1];
		if(g[j]==2) ans+=(n-j+1);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c<=10) while(T--) solve();
	else while(T--) solve2();
	return 0;
}