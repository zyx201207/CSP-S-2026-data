#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int a[N];
int n,d;
int hdp[N],dis[N],fr[N],lst[N];
int solve(int L,int R){
	if(R-L+1<4) return 0;
	for(int i=L;i<=R;i++){
		fr[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
	}
	int ans=0;
	for(int i=L;i<=R;i++){
		dis[i]=0;lst[0]=i;
		for(int j=i+1;j<=R;j++){
			dis[j]=dis[max(i,fr[j])]+1;
			lst[dis[j]]=j;
		}
		hdp[i]=1;
		for(int j=i+1;j<=R;j++){
			int cur=hdp[lst[dis[j]-1]];
			if(fr[j]-1>=i) cur-=hdp[fr[j]-1];
			ans+=(cur==2);
			hdp[j]=hdp[j-1]+cur;
		}
	}
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int D=a[2]-a[1];
		bool flag=true;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=D) flag=false;
		}
		if(flag and n>=5000){
			int cnt=d/D;
			if(cnt) cout<<max(0ll,n-2ll*cnt+1ll)<<"\n";
			else cout<<0<<"\n";
			continue;
		}
		int lst=1;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i+1]-a[i]>d or i==n){
				ans+=solve(lst,i);
				lst=i+1;
			}
		}
		cout<<ans<<"\n";
	}
}
