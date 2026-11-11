#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans,d,value;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	priority_queue<int,vector<int>,greater<int>> q;
	value=a[1];
	for (int i=1;i<=n;i++){
		d+=q.size()*(a[i]-value);
		q.push(a[i]);
		value=a[i];
		while (d>m){
			d-=value-q.top();
			q.pop();
		}ans=max(ans,(int)q.size());
	}cout<<ans;
	return 0;
}
