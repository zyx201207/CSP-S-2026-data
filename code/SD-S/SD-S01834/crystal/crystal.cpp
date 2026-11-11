#include<bits/stdc++.h>
#define deb(a) cerr<<#a<<"="<<(a)<<endl 
using namespace std;
#define i64 long long
#define int i64
const int maxn=5e5+10;

int n,m,a[maxn];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,j=1,ans=0;
	for(int i=1;i<=n;++i){
//		deb(a[i]);deb(sum);
		sum+=a[i];
		while(a[i]*(i-j+1)-sum > m)
			sum-=a[j++];
		ans=max(ans,i-j+1);
	}cout<<ans;
}
