// ~75
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int mx=0;
stack<int>v;
vector<int>vv;
bool vis[200005];
map<int,int>cnt;
int ans=0;
void dfs(int dep){
	if(dep==m){
		ans=max(ans,v.top());
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(!v.empty())v.push(v.top()&a[i]);
			else v.push(a[i]);
			dfs(dep+1);
			v.pop();
			vis[i]=0;
		}
	}
	return;
}
signed main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	/* #7 */
	if(m==n){
		int xx=a[n];
		for(int i=1;i<=n-1;i++){
			xx&=a[i];
		}
		cout<<xx<<endl;
		return 0;
	}
	/* #16-#17 */
	if(mx<=4){
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		if(cnt[4]>=m)cout<<4<<endl;
		else if(cnt[3]>=m)cout<<3<<endl;
		else if(cnt[2]+cnt[3]>=m)cout<<2<<endl;
		else if(cnt[1]+cnt[3]>=m)cout<<1<<endl;
		else cout<<0<<endl;
		return 0;
	}
	/* #13 */
	bool t13=1;
	for(int i=1;i<=n;i++){
		if(a[i]&(a[i]+1)){
			t13=0;break;
		}
	}
	if(t13){
		sort(a+1,a+n+1);
		cout<<a[n-m+1]<<endl;
		return 0;
	}
	/* #14-#15 */
	bool t14_15=1;
	if(n&(n-1)==0){
		for(int i=1;i<=n;i++){
			if(a[i]==i-1)t14_15=0;
		}
	}else t14_15=0;
	if(t14_15){
		int cur=a[n];
		for(int i=n;i>=n-m+1;i--)cur&=a[i];
		cout<<cur<<endl;
		return 0;
	}
	/* #1-#6 #8-#10 */
	dfs(0);
	cout<<ans<<endl;
	return 0;
}
