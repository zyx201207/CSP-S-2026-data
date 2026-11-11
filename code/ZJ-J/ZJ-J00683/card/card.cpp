#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans[500005];
void solve(ll x){
	stack<ll>st;
	map<ll,bool>mp;
	for(int i=x;i<=n;i++){
		if(mp[a[i]]==1){
			while(mp[a[i]]==1){
				mp[st.top()]=0;
				st.pop();
			}
		}
		st.push(a[i]);
		mp[a[i]]=1;
	}
	while(!st.empty()){
		ans[st.top()]++;
		st.pop();
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)solve(i);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
