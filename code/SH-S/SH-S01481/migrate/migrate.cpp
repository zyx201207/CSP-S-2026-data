#include<bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		long long n,d,a[2000005],sum=0,ans=0,b[2000005],f[2000005];
		memset(a,0,sizeof(a));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=0;
			f[i]=0;
			sum=a[i]-a[i-1];
		}
		for(int i=1;i<=n;i++){
			if(d/sum*i+2<=n) b[(d/sum*i+2)]++;
			f[i]=f[i-1]+b[i];
			ans+=f[i];
		}
		cout<<ans;
	}
	return 0;
}

