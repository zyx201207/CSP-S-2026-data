#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+2;
int n,m;
long long a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans<<"\n";
	return 0; 
} 
