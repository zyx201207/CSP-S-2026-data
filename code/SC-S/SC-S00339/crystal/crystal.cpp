#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define max(a,b) ((a)>(b)?(a):(b))
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	queue<int>q;
	int sum=0,ans=0;
	for(int i = 1;i<n;i++){
		q.push(i);
		sum+=q.size()*(a[i+1]-a[i]);
		while(!q.empty()&&sum>m){
			sum-=a[i+1]-a[q.front()];
			q.pop();
		}
		ans=max(ans,q.size());
	}
	cout << ans+1;
	return 0;
}