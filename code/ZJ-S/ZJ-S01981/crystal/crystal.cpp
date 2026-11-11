#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0;
	int ans=1;
	for(int i=1,j=1;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-j);
		while(cnt>m){
			j++;
			cnt-=(a[i]-a[j-1]);
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}