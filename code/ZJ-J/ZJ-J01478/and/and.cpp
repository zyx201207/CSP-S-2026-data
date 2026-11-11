#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N];
bool f[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(f[j]||((a[j]>>i)&1)==0) cnt++;
		}
		if(n-cnt>=m){
			ans+=(1<<i);
			//cout<<(1<<i)<<'\n';
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)==0) f[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}