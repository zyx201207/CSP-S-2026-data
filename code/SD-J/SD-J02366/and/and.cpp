#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int minn=1e18;
	for(int i=n;i>=n-q+1;i--){
		if(a[i]<minn){
			minn=a[i];
		}
	}
	cout<<minn;
	return 0;
}

