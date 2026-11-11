#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=5e5+5;

int n,m;

int a[N];

signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	queue<int> q;
	int tot=0,cnt=0,ans=1;
	
	for(int i=1;i<=n;i++){
		tot+=cnt*(a[i]-a[i-1]);
		cnt++;
		while(q.size()&&tot>m){
			int x=q.front(); q.pop();
			cnt--; tot-=a[i]-x;
		}
		ans=max(ans,cnt);
		q.push(a[i]);
	}
	
	cout<<ans;
	
	return 0;
}
/*

5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 5
-1000000000000
-1000000000000
-1000000000000
-1000000000000
1000000000000


*/