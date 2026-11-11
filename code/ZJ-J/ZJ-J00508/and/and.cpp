#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans;
bool vv[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=29;j>=0;j--){
		int ct=1ll<<j;
		int cnt=0;
	//	cout<<j<<'\n';
		for(int i=1;i<=n;i++){
			if(vv[i])continue;
			if(a[i]&ct)cnt++;
		}
	//	cout<<'\n';
		if(cnt>=m){
			ans+=ct;
			for(int i=1;i<=n;i++){
				if((a[i]&ct)==0)vv[i]=1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//0011
//1111
//1100
//1100
