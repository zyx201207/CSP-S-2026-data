#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2000005;
int c,t,n,d,ans;
int fr[MAXN],ba[MAXN],g[MAXN],le[MAXN],ri[MAXN];
int a[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		int sa=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++){
			fr[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			ba[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			if(a[i]-a[i-1]>d){
				sa++;
			}
			g[i]=sa;
		}
		for(int i=1;i<=n;i++){
			if(i+3<=ba[i])ri[i+2]+=1,le[i]+=1;
			for(int j=ba[i]+1;j<=ba[ba[i]];j++){
				if(ba[i]-fr[j]==1)ri[j-1]+=1,le[i]+=1;
			}
		}
		for(int i=n;i>=1;i--){
			le[i]=le[i+1]+le[i];
			ri[i]=ri[i+1]+ri[i];
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ri[j]+1==le[i]&&g[i]==g[j])
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;	
} 
