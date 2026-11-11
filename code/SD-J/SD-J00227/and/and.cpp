#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;

int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=2147483647;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

