#include<bits/stdc++.h>
using namespace std;
typedef long long Int;
typedef pair<Int,Int> pir;

Int n,m,a[500005],ans=0;

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(Int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	Int l=1,sum=0;
	for(Int i=1;i<=n;i++){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m)sum-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	
	return 0;
}