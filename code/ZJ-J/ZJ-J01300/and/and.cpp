#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m,a[200010][2],p,cnt,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	for(int k=30;k>=0;k--){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i][p]&(1<<k)){
				a[++cnt][1-p]=a[i][p];
			}
		}
		if(cnt>=m){
			ans+=(1<<k);
			p=1-p;
			n=cnt;
		}
	}
	cout<<ans<<endl;
	return 0;
}
