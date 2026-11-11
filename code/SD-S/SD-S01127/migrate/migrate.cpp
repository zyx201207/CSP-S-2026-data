#include<bits/stdc++.h>
#define int long long
using namespace std;
int c;
int n,d,a[2000005],f[5005][5005],dis[5005][5005];
void sol(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12){
		int gc=a[2]-a[1];
		int b=d/gc;
		if(b<=1) cout<<0<<"\n";
		else cout<<max(0ll,n-(b*2-1))<<"\n";
		return;
	}
	for(int i=1;i<=n;i++){
		int s=0,fl=0;
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) fl=1;
			if(fl){dis[i][j]=-1,f[i][j]=0;continue;}
			if(s+a[j]-a[j-1]>d||j==i+1) dis[i][j]=dis[i][j-1]+1,s=a[j]-a[j-1];
			else dis[i][j]=dis[i][j-1],s+=a[j]-a[j-1];
			if(dis[i][j]==1) f[i][j]=1;
			else f[i][j]=0;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<=j-1;k++) f[i][j]+=(dis[i][k]+dis[k][j]==dis[i][j]?f[i][k]*f[k][j]:0);
			if(f[i][j]==2) ans++;
		}
	}cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;cin>>c>>T;
	while(T--) sol();
}

