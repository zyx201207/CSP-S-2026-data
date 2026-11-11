#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,T;
int n,d,a[N],ans;
void solve(){
	cin>>n>>d;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=-0x3f3f3f3f3f3f3f3f,a[n+1]=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++){	//枚举左1 
		int stp=upper_bound( a+1,a+n+1,a[i]+d )-a-1;//奋力一跳，保证答案可行 
		if( stp==i+1||stp==i )continue; 
		//[stp+1,j]都为可行解
		//区间内的所有点往后一直奋力一跳，路过的点的数量就是答案
		set<int > v;		//去重用 
		for(int j=upper_bound(a+1,a+n+1,a[stp-2]+d)-a;j<=n;j++){
			if( a[j]-a[stp-1]>d )break;
			int l=j;
			while(1){
				v.insert( l );
				int k=upper_bound(a+1,a+n+1,a[l]+d)-a-1;
				if( a[k]-a[stp]<=d )break;
				if( l==k )break;
				l=k;
			}
		}
		int p=i,cnt=1;
		while(1){
			int k=lower_bound(a+1,a+n+1,a[p]-d)-a;
			if( k==p )break;
			if( a[stp-1]-a[k]<=d )break;
			p=k;++cnt;
		}
		ans+=cnt*v.size();
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>T;
	while(T--)solve();
	return 0;
}
