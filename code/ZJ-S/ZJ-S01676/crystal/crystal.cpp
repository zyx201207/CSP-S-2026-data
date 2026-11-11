#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		int j=i-x+1;
		int need=x*a[i]-(s[i]-s[j-1]);
		if(need<=m)return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<" ";
	}
	int l=1,r=n;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
//			cout<<mid<<"true\n";
		}
		else{
//			cout<<mid<<"false\n";
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
