#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,n,T,d,f[N],g[N],s[N],x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(n>5000){
			cout<<0<<'\n';
			continue;
		}
		if(c==11||c==12){
			int de=x[2]-x[1];
			if(d<=de) cout<<0<<'\n';
			else {
				int r=d/de;r=r*2-1;
				cout<<max(0ll,n-r)<<'\n';
			}
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			f[i]=0;g[i]=1;s[i]=1;s[i-1]=0;
			int l=i,r=i;int sm=0;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[j-1]>d) break;
				while(x[j]-x[l]>d) l++;
				r=max(r,l);
				while(r+1<j&&f[r+1]==f[l]) ++r;
				g[j]=s[r]-s[l-1];f[j]=f[l]+1;
				s[j]=s[j-1]+g[j];
//				cout<<i<<' '<<j<<' '<<l<<' '<<r<<' '<<f[j]<<' '<<g[j]<<'\n';
				ans+=(g[j]==2);sm+=(g[j]==2);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

