#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k,a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	queue<int>q;
	int cnt=0,sum=0,ans=0;
	for(int i=1;i<=n;++i){
	  ++cnt;
	  sum+=a[i];
	  q.push(i);
	  while(cnt*a[i]-sum>k){
		--cnt;
		sum-=a[q.front()];
		q.pop();
	  }
	  ans=max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}