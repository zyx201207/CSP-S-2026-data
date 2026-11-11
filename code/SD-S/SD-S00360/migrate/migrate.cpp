#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,a[N];
int minn=1e18;
int ans;
unordered_map<int,int> mp;
int cnt=1;
void dfs(int u,int ed,int ju){
	if(u>ed) return ;
	if(u==ed){
		if(ju==minn){
			++cnt;
		}
		if(ju<minn){
			minn=ju;
			cnt=1;
		}
		return ;
	}
	for(int i=1;i<=d;i++){
		if(mp.count(u+i)){
			dfs(u+i,ed,ju+1);
		}
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		minn=1e18;
		mp.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mp[a[i]]=1;
		}
//		for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=1;
				minn=1e18;
				dfs(a[i],a[j],0);
//				cout<<"~~~~~~"<<i<<" "<<j<<" "<<cnt<<" "<<minn<<"\n";
				if(cnt==2) ++ans;
			}
		}
//		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

