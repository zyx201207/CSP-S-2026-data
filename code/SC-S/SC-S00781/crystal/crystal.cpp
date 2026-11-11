#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int res=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&res>m)res-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
		if(i!=n)res+=(i-j+1)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}