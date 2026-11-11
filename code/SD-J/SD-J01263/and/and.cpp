#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const int N=2e5+10;
int a[N];
int ans;
int n,m;
const int inf=0x3f3f3f3f3f3f3f3f;
void dfs(int pos,int cnt,int sum){
//	cout<<s<<endl;
	if(cnt==m){
//		int sum=inf;
//		for(int i=1;i<=n;i++){
//			if(s[i]=='1'){
//				sum=sum&a[i];
//			}
//		}
		ans=max(ans,sum);
		return ;
	}
	if(pos>n){
		return ;
	}
	dfs(pos+1,cnt+1,sum&a[pos]);
	dfs(pos+1,cnt,sum);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,inf);
	cout<<ans;
	return 0;
}

/*

4 2
3 15 12 12

5 3
31 3 1 15 7

*/
