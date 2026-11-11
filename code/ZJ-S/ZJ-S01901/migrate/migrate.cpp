#include<bits/stdc++.h>
#define deal(a) if(i>a)if(x[i]-x[i-a]<=d)f[i]=max(f[i],a)
using namespace std;
long long x[2000010];
int f[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(f,0,sizeof f);
		long long n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i){
			cin>>x[i];
			for(int j=1;j<3;++j)deal(j);
		}
		for(int i=1;i<=n;++i){
//			cout<<f[i]<<' ';
			if(f[i]==2&&f[i+1]==2){
				ans++;
			}
		}
//		cout<<'\n';
		cout<<ans<<'\n';
	}
	return 0;
}
