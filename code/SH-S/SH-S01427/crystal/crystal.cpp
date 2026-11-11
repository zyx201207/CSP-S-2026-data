#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500009];
queue<int> q;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1,nw=0,sum=0;
	for(int i=1;i<=n;i++){
		if(sum+(a[i]-a[i-1])*q.size()<=m){
			sum=sum+(a[i]-a[i-1])*q.size();
			q.push(a[i]);
			ans=max(ans,(long long)q.size());
		}else{
			while(!q.empty() and sum+(a[i]-a[i-1])*q.size()>m){
				sum-=a[i-1]-q.front();
				q.pop();
			}
			sum=sum+(a[i]-a[i-1])*q.size();
			q.push(a[i]);
		}
	}
	cout<<ans;
	return 0;
}
