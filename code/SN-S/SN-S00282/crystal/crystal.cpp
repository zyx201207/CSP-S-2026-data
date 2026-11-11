#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cnt,ans,now;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1,j=1;j<=n;j++){
		cnt+=(a[j]-a[j-1])*(j-1-i+1);
		now++;
		while(i<j&&cnt>m){
			now--;
			cnt-=(a[j]-a[i]);
			i++;
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
}
