//吴雨桐 西安市第六中学 SN-J00647
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ad = a[n];
	//cout<<ad<<endl;
	int sum = 0;
	for(int i = n-1;i>=n-m+1;i--){
		ad &= a[i+sum];
	}
	cout<<ad;
	return 0;
} 
