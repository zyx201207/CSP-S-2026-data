#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010];
int cnt;
int ans;
int f;
priority_queue<int,vector<int>,greater<int> > q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			f=1;
			break;
		}
	}
	if(!f) cout<<n;
	else{
		q.push(a[1]);
		for(int i=2;i<=n;i++){
			if(cnt<=m){
				cnt+=q.size()*(a[i]-a[i-1]);
				q.push(a[i]);
			}
			if(cnt>m){
				while(cnt>m){
					cnt-=a[i]-q.top();
					q.pop();
				}
			}
			int len=q.size();
			ans=max(ans,len);
		}
		cout<<ans;
	}
	return 0;
}
