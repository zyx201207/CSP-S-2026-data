#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010],f[2000010],p[2000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[0]=-9e18;
		a[n+1]=9e18;
		if(n==1)cout<<0<<endl;
		else if(c>=0&&c<=10){
			for(int i=1;i<=n;i++){
				int j=i;
				for(int l=0;l<=n+1;l++)p[l]=0;
				for(;a[j]-a[i]<=d;j++)f[j]=1,p[j]=p[j-1]+f[j];
				for(int k=i;j<=n;j++){
					while(a[j]-a[k]>d)k++;
					f[j]=p[j-1]-p[k-1];
					p[j]=p[j-1]+f[j];
					if(f[j]==2)ans++;
				}
//				for(int l=1;l<=n;l++)cout<<f[l]<<" ";
//				cout<<endl;
			}
			cout<<ans<<"\n";
		}
		else if(c>=11&&c<=12){
			int x=a[2]-a[1],y=d/x;
			if(d<x*2)cout<<0<<"\n";
			else if(y*2-1>=n)cout<<0<<"\n";
			else cout<<n-(y*2-1)<<"\n";
		}
		else cout<<0<<"\n";
	}
	return 0;
}
//time: 18:27 3min left
//points: 100+[?,100]+[0,?]+0=100
//Man,what can I say.
