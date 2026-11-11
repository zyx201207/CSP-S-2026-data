#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=2e5+2;
int n,m;
int a[MAXN];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for (int k=60;k>=0;k--){
		int cnt=0;
		for (int i=1;i<=n;i++){
			if ((ans|(1LL<<k))==((ans|(1LL<<k))&a[i])){
				cnt++;
			}
		}
		if (cnt>=m){
			ans|=(1LL<<k);
		}
	}
	cout<<ans<<endl;
	return 0; 
}
