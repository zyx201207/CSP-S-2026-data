#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N],r[N],dis[N],f[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,m,ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(n<=5000){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[j]-a[i]<=m)r[i]=j;
					else break;
				}
			}
			for(int i=1;i<n;i++){
				int x=r[i],la=i,sum=0;
				while(1){
					sum++;
					for(int j=la+1;j<=x;j++)dis[j]=sum;
					la=x;
					x=r[x];
					if(x==la)break;
				}
				int p1=i,p=i;
				for(int j=1;j<=n;j++)f[j]=0;
				f[i]=1,dis[i]=0;
				for(int j=i+1;j<=x;j++){
					while(p<=j&&dis[p+1]<dis[j])p++;
					while((r[p1]<j||dis[p1]!=dis[j]-1)&&p1<=j)p1++;
					f[j]=f[p]-f[p1-1];
					if(f[j]==2)ans++;
					f[j]+=f[j-1];
				}
	//			cout<<la<<'\n';
	//			for(int j=1;j<=n;j++)cout<<dis[j]<<' ';
	//			cout<<'\n';
	//			for(int j=1;j<=n;j++)cout<<f[j]<<' ';
	//			cout<<'\n';
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<0<<'\n';
	}
	return 0;
}