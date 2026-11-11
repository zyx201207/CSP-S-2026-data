#include<bits/stdc++.h>
#define int long long
#define U(a,b,c) for(int a=b;a<=c;a++)
#define D(a,b,c) for(int a=b;a>=c;a--)
using namespace std;
const int N=5e5+10;
int a[N],n,m;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	U(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0,ans=1;
	U(i,2,n){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}