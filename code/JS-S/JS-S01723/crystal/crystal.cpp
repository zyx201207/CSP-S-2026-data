#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],mx=1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int pre=1,last=0,sum=0;
	for(int i=2;i<=n;i++){
		sum+=pre*(a[i]-a[i-1]);
		pre++;
		while(sum>m){
			sum-=a[i]-a[last];
			last++;
			pre--;
		}mx=max(mx,pre);
	}cout<<mx;
	return 0;
}
