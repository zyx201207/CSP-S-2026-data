#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int IIID,TTTT,n,d;
int x[N];
int ll[N],rr[N],f[N],s[N],g[N];
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	cin>>IIID>>TTTT;
	if(IIID<=12)freopen("migrate.out","w",stdout);
	while(TTTT--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			ll[i]=1;
			rr[i]=n;
		}
		for(int i=2;i<=n;i++){
			ll[i]=ll[i-1];
			while(x[ll[i]]+d<x[i])ll[i]++;
		}
		for(int i=n-1;i>=1;i--){
			rr[i]=rr[i+1];
			while(x[rr[i]]-d>x[i])rr[i]--;
		}
		int ans=0;
		if(IIID<=10){
			for(int j=1;j<=n;j++){
				int l=0,r=j-1;
				for(int i=0;i<=j;i++){
					f[i]=0;
					s[i]=0;
					g[i]=0;
				}
				f[j]=1;
				s[j]=1;
				g[j]=0;
				for(int i=j+1;i<=n;i++){
					g[i]=g[ll[i]]+1;
					if(g[i]!=g[i-1]){
						l=r+1;
						r=i-1;
					}
					if(l<ll[i])l=ll[i];
					f[i]=s[r]-s[l-1];
					s[i]=s[i-1]+f[i];
					ans+=f[i]==2;
				}
			}
			cout<<ans<<"\n";
		}else if(IIID<=12){
			for(int j=1;j<=1;j++){
				int l=0,r=j-1;
				for(int i=0;i<=j;i++){
					f[i]=0;
					s[i]=0;
					g[i]=0;
				}
				f[j]=1;
				s[j]=1;
				g[j]=0;
				for(int i=j+1;i<=n;i++){
					g[i]=g[ll[i]]+1;
					if(g[i]!=g[i-1]){
						l=r+1;
						r=i-1;
					}
					if(l<ll[i])l=ll[i];
					f[i]=s[r]-s[l-1];
					s[i]=s[i-1]+f[i];
					ans+=(f[i]==2)*(n-i+1);
				}
			}
			cout<<ans<<"\n";
		}else{
			
		}
	}
	return 0;
}
