#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,ans=1,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2,j=1;i<=n;i++){
		m-=(a[i]-a[i-1])*(i-j);
		while(m<0)
			m+=a[i]-a[j++];
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
} 
