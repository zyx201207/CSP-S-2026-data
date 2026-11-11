#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int C,T,n,d,a[N],f[N],c[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(C<=10){
			int ans=0;
			for(int i=1;i<=n;i++){
				f[i-1]=0;f[i]=1;c[i]=0;
				for(int j=i,k=i,o=i;j<=n;j++){
					while(a[j]-a[k]>d)k++;
					o=max(o,k);
					while(o<j-1&&c[k]==c[o+1])o++;c[j]=c[k]+1;
					f[j]=f[o]-f[k-1];if(f[j]==2)ans++;
					f[j]+=f[j-1];
				}
			}
			cout<<ans<<'\n';continue;
		}
		
	}
} 