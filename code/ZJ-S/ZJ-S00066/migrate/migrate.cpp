#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,i,n,m,j,k,flagg,l[2000010],xch,ans,t,flag,a[2000010],dis[5010][5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	if(c<=6){
		while(T--){
			cin>>n>>m;ans=0;
			for(i=1;i<=n;i++)cin>>a[i];
			for(i=1;i<=n;i++)
				for(j=i;j<=n;j++)
					dis[i][j]=1e9;
			t=1;l[1]=1;
			for(i=2;i<=n;i++){
				while(a[i]-a[t]>m)t++;
				l[i]=t;
			}
			for(i=1;i<=n;i++){
				dis[i][i]=0;
				for(j=i+1;j<=n;j++){
					if(a[j]-a[j-1]>m)break;
					dis[i][j]=dis[i][l[j]]+1;
				}
			}
			for(i=1;i<=n;i++){
				for(j=i+3;j<=n;j++){
					if(a[j]-a[j-1]>m)break;
					flag=0;
					for(k=i+2;k<j;k++)
						if(dis[i][k-1]==dis[i][k]&&dis[k-1][j]==dis[k][j]&&dis[i][k]+dis[k][j]==dis[i][j])flag++;
					if(flag==1)ans++;
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	if(c==11||c==12){
		while(T--){
			cin>>n>>m;
			for(i=1;i<=n;i++)cin>>a[i];
			xch=m/(a[2]-a[1]);
			if(xch<=1)cout<<0<<'\n';
			else cout<<max(0ll,n-2*xch+1)<<'\n';
		}
		return 0;
	}
	while(T--){
		cin>>n>>m;ans=0;
		for(i=1;i<=n;i++)cin>>a[i];
		t=1;l[1]=1;
		for(i=2;i<=n;i++){
			while(a[i]-a[t]>m)t++;
			l[i]=t;
		}
		for(i=n;i>=1;i--){
			if(a[i]-a[1]<=m)break;
			ans=ans+max(0ll,l[l[i]+2]-l[l[i]+1]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
