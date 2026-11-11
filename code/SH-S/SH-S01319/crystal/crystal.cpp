#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN 500005
int n,m;
int a[MAXN],b[MAXN],sum,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[n]-a[i];
		sum+=b[i];
	}
	ans=n;
	while(sum>m){
		sum-=(b[ans-1]-b[ans])*(ans-1);
		ans--;
	}
	cout<<ans;
	return 0;	
} 
