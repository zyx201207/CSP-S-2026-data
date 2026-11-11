#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=500020;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,l=1,sum=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(l<i){
			if(a[i]*(i-l)-sum>m) sum-=a[l++];
			else break;
		}
		sum+=a[i];ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
//14:52 finish 100pts
//14:55 pass all big samples,0.6s max
//lsy give me luck to get 100pts