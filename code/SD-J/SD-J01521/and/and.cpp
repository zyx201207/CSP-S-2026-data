#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],ans=-0x3f3f3f3f3f3f,cnt,t;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		cout<<ans;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]&a[i]);
		}
		cout<<ans;
	}
	return 0;
}

