#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,ans,a[500010],b[500010];
map <int,int> mp;
bool check(int x){
	int cnt=2e18;
	mp.clear();
	priority_queue <int,vector <int> > q;
	for(int i=1;i<=x;i++)q.push(a[i]);
	for(int i=1;i+x-1<=n;i++){
		while(!q.empty()&&mp.count(q.top()))q.pop();
		if(i>=2)q.push(a[i+x-1]);
		cnt=min(cnt,q.top()*x-(b[i+x-1]-b[i-1]));
		mp[a[i]]=1;
	}
	while(!q.empty())q.pop();
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],b[i]=b[i-1]+a[i];
	l=1;r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}