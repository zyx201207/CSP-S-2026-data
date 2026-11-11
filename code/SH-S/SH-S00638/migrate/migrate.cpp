#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
int c,t,n;
long long d,a[maxn],f[maxn][maxn],g[maxn][maxn],cnt,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int len=2;len<=n;len++){
			for(int l=1,r=l+len-1;r<=n;l++,r++){
				if(a[r]-a[l]<=d){
					f[l][r]=g[l][r]=1;
					continue;
				}
				if(len==2){
					f[l][r]=1e18;
					continue;
				}
				int pos=upper_bound(a+l,a+1+n,a[l]+d)-a-1;
				f[l][r]=f[pos][r]+1;
				int cnt=0;
				for(int k=l+1;k<=pos;k++)
					if(f[k][r]+1==f[l][r]&&f[k][r]<1e18)cnt+=g[k][r];
				if(cnt==2)ans++;
				g[l][r]=cnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
} 
