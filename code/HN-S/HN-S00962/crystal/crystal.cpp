#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,s[N]; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int idx=1;
	for(int i=1;i<=n;i++){
		while((i-idx)*a[i]-s[i-1]+s[idx-1]>m)idx++;
		ans=max(ans,i-idx+1);
	}
	cout<<ans;
	return 0;
} 
