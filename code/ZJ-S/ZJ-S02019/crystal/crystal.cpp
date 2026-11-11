#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500000+5;
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=n;
	__int128 cnt=0,one=1;
	int ans=0;
	for(int r=n;r>=1;r--){
		if(l==1){
			ans=max(ans,(int)(r-l+1));
			break;
		}
		while(l-1>=1&&cnt+(a[r]-a[l-1])<=m){
			cnt+=a[r]-a[l-1];
			l--;
		}
		ans=max(ans,(int)(r-l+1));
		cnt-=one*(r-l)*(a[r]-a[r-1]);
	}
	cout<<ans;
	return 0;
}
