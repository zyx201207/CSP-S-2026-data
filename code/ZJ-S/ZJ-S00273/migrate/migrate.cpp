#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t,n,d,ans[2201][2201],f[2201][2201],a[100020],anss,l=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1&&i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) l=0;
		}
		if(l==1){
			int y=(a[2]-a[1])/2;
			if(y==1) cout<<0<<"\n";
			else cout<<n+1-2*y<<"\n";
		}else{
			for(int i=1;i<n;i++){
			for(int j=1;j+i<=n;j++){
				if(a[i+j]-a[j]<=d){
					ans[j][i]=1;
					f[j][i]=1;
				}else{
					ans[j][i]=INT_MAX;
					for(int p=1;p<i;p++){
						if(ans[j][i]>ans[j][p]+ans[j+p][i-p]){
							ans[j][i]=ans[j][p]+ans[j+p][i-p];
							f[j][i]=0;
						}
						f[j][i]+=(ans[j][i]==ans[j][p]+ans[j+p][i-p])*f[j][p]*f[j+p][i-p];
					}
				}
				if(f[j][i]==2) anss++;
			}
		}
		cout<<anss<<'\n';
		}
	}
	return 0;
}
