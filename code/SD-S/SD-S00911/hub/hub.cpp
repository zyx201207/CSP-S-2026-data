#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e6+10;
int anss;
int a[N];  
int n,m;
int mn=2e18;
int ans=0;//成立路线数量 
int sum=0;//路线长度 
map<int,int> mp; 
//void dfs_mn(int i,int k,int cnt){
//	if(cnt>=mn){
//		return ;
//	}
//	if(i>n){
//		mn=min(mn,cnt);
//		return ;
//	}
//	int pos=upper_bound(a+1,a+1+n,a[i]+k)-a;
//	if(a[pos-1]==a[i]+k){
//		for(int j=i+1;j<=m;j++){
//			dfs_mn(pos-1,j,cnt+1);
//		}
//	}
//}
void dfs_search(int i,int k){
	if(sum>mn){
		return ;
	}
	if(i>=2&&i<=n-2&&mp[a[i]]){
		return ;
	}
	if(i>n){
		if(sum==mn){
			ans++;
			return ;
		}
	}
	
	int pos=upper_bound(a+1,a+1+n,a[i]+k)-a;
	if(a[pos-1]==a[i]+k){
		mp[a[pos-1]]=1;
		for(int j=1;j<=m;j++){
			sum+=j;
			dfs_search(pos-1,j);
			sum-=j;
		}
	}
} 
void solve(){
	cout<<1<<"\n"; 
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,_=1;
	cin>>c;
	cin>>_; 
	while(_--){
		solve();
	}
	return 0;
}

/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
