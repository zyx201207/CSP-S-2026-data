#include<bits/stdc++.h>
#define rep(i,a,b) for(long long i=a;i<=b;i++)
#define int long long
using namespace std;
int n,m;
int a[500001];
int s[500001];
inline pair<bool,int> calc(int x){
	int l=0,r=x;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(abs(a[x]*(x-mid)-(s[x-1]-s[mid-1]))>m)
			l=mid;
		else
			r=mid;
	}
	if(r==x)
		return make_pair(false,-1);
	//return abs(a[x]*(x-l)-(s[x-1]-s[r-1]));
	return make_pair(true,x-r+1);
}
long long ans=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rep(i,1,n)
		cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	rep(i,1,n)
		s[i]=s[i-1]+a[i];
	rep(i,1,n){
		pair<bool,int> tmp=calc(i);
		if(tmp.first)
			ans=max(ans,tmp.second);
	}
	cout<<ans;
	return 0;
}
