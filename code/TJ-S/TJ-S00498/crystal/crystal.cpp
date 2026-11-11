#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;

int n,m;
int a[N],c[N],sum;
int ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	for(int i=2,j=1;i<=n;++i){
		int tc=a[i]-a[i-1];
		while(j<=i&&sum+(i-j)*tc>m){
			sum-=a[i-1]-a[j];
			++j;
		}
		sum+=(i-j)*tc;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
} 
