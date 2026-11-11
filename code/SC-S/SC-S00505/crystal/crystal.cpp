#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
queue<int> q;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0,ss=0;
	for(int i=1;i<=n;i++){
		ss+=(a[i]-a[i-1])*q.size();
		q.push(a[i]);
		while(q.size()>1&&ss>m){
			ss-=a[i]-q.front();
			q.pop();
		}
		ans=max(ans,(int)q.size());
	}
	cout<<ans;
	return 0;
}