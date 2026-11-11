#include<bits/stdc++.h>
#define int long long
#define rep(i,a,n) for(int i=a; i<=n; i++)
#define dop(i,a,n) for(int i=n; i>=a; i--)
#define cios cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
using namespace std;
const int N=2e6+10;
int c,T,n,d,a[N],f[N],pre[N],ans,t[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cios;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		rep(i,1,n) cin>>a[i];
		rep(i,1,n){
			f[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			pre[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			//cout<<"i="<<i<<" "<<f[i]<<" "<<pre[i]<<"\n";
		}
		rep(i,1,n){
			rep(j,i+1,n){
				if(a[j]-a[i]<=d) continue;
				int x=f[i],cnt=0;
				while(x<j){
					if(min(j,a[f[x]])-a[x-1]<=d){
						cnt++;
						if(a[x-1]-a[pre[x]-1]<=d&&pre[x]-1>=i){cnt=0;break;}
					}
					if(cnt==2) break;
					if(min(j,f[x])-a[x-2]<=d&&x-2>=i){cnt=0;break;}
					x=f[x];
					while(pre[x]==x-1) x=f[x];
				}
				if(cnt==1){
					ans++;
					//cout<<i<<" "<<j<<"\n"; 
				}
			}
		}
		cout<<ans<<"\n";
		rep(i,0,n) t[i]=pre[i]=f[i]=0;
	}
	return 0;
}
