#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt=0,ans=0;
	for(int r=1,l=1;r<=n;r++){
		cnt+=(a[r]-a[r-1])*(r-l);
		while(cnt>m){
			cnt-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
