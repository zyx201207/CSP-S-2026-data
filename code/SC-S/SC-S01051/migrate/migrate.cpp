#include<iostream>
using namespace std;
#define N 2000001
int c,t,n,i,j,l,dp[N];
long long d,a[N],rd[N],cnts[N],ans;
inline void solve(){
	cin>>n>>d;
	for(i=1;i<=n;++i)cin>>a[i];
	if(n<4){
		cout<<"0\n";
		return;
	}
	if(c==11||c==12){
		ans=d/(a[2]-a[1]);
		if(ans<2||(ans<<1)>=n)cout<<"0\n";
		else cout<<n-(ans<<1)+1<<'\n';
		return;
	}
	ans=0;
	for(j=1;j<n;++j){
		l=j;dp[j]=0;cnts[j]=1;cnts[j-1]=0;rd[0]=j;
		for(i=j+1;i<=n;++i){
			while(a[l]<a[i]-d)++l;
			if(l==i)break;
			dp[i]=dp[l]+1;
			cnts[i]=cnts[rd[dp[l]]]-cnts[l-1]+cnts[i-1];
			if(cnts[i]-cnts[i-1]==2)++ans;
			rd[dp[i]]=i;
		}
	}cout<<ans<<'\n';
	return;
}int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;while(t--)solve();
	return 0;
}