#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
long long n,m,a[N],s[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	for(int i=1,j=0;i<=n;i++){
		if((i-j)*a[i]-(s[i]-s[j])>m)j++;
		else ans=max(ans,i-j);
	}
	cout<<ans;
	return 0;
} 
