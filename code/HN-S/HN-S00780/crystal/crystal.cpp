#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m,ans=1,a[N];
unsigned long long cnt;
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
	for(int i=1,j=1;i<=n;i++){
		while(cnt+(a[j+1]-a[j])*(j-i+1)<=m&&j<n){
			cnt+=(a[j+1]-a[j])*(j-i+1);
			j++;
		}
		ans=max(ans,j-i+1);
		cnt-=(a[j-1]-a[i]);
		if(j>n)break;
	}
	cout<<ans;
	return 0;
}
