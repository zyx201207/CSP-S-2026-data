#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=1;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int cnt=0,sum=0,st=1;
	for(int i=2;i<=n;i++){
		cnt+=(i-st)*(a[i]-a[i-1]);
		if(cnt>m)cnt-=a[i]-a[st],st++;
		ans=max(ans,i-st+1);
	}cout<<ans;
	return 0;
}