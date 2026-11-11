#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,l,r,ans=1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=n;
	for(r=n;r>=1;r--){
		m+=(r+1-l)*(a[min(n,r+1)]-a[r]);
		while(l-1>0&&m-(a[r]-a[l-1])>=0){
			m-=(a[r]-a[l-1]);
			l--;
		}
		ans=max(ans,r-l+1);
		if(l<=1){
			break;
		}
	}
	cout<<ans;
	return 0;
}

