#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int mx=-1;
	int left=1;
	for(int i=1;i<=n;i++){
		while(left<=i&&a[i]*(i-left)-(s[i-1]-s[left-1])>m)++left;
		mx=max(mx,(i-left+1));
	//	cout<<left<<" "<<i<<" "<<a[i]*(i-left)-(s[i-1]-s[left-1])<<"???\n";
	}cout<<mx;
	return 0;
}
