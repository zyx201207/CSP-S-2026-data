#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[1000010],b[1000010],f[1000010],y[1000010];
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)f[j]=1e18;
		y[i]=f[i]=1;
		int x=0;
		for(int j=i;j<=n;j++){
//			cout<<f[j]<<' ';
			if(f[j]>=1e18)break;
//			if(j>=3&&f[j-1]!=f[j]&&f[j-1]==f[j-2]&&f[j-2]!=f[j-3]){
//				ans++;
//				break;
//			}if(j>=3&&f[j-1]==f[j-2])break;
			for(int k=j+1;k<=n;k++){
				if(a[k]-a[j]<=d){
					if(f[k]==f[j]+1)y[k]+=y[j];
					else if(f[k]>f[j]+1)y[k]=y[j];
//					cout<<k<<":"<<(f[k]>=1e18?-1:f[k])<<' '<<f[j]+1<<' '<<y[k]<<"  ";
					f[k]=min(f[k],f[j]+1);
				}else{
					break;
				}
			}
		}for(int j=1;j<=n;j++){
			if(y[j]==2)ans++;
			y[j]=0;
		}
//		cout<<x<<'\n';
//		cout<<f[n-1]<<' '<<f[n-2]<<' '<<f[n-3]<<'\n';
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5



0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


1 1
10 3
1 4 7 8 9 10 11 12 15 18

*/
