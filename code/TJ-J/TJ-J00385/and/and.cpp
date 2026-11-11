#include<iostream> 
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for(int i=n;i>=n-m;i--){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}
