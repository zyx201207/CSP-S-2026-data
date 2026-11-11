#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,INF=1e18;
int n,m,a[N],jl[N],s[N];
deque<int>q;
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
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		jl[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+jl[i];
	}
	int ans=1,su=0;
	for(int i=1;i<n;i++){
		q.push_back(i);
		su+=(q.size())*jl[i];
		while(su>m&&q.size()){
			su-=(s[i]-s[q.front()-1]);
			q.pop_front();
		}
		if(ans<q.size()+1){
			ans=q.size()+1;
		}
	}
	cout<<ans;
	return 0;
}
