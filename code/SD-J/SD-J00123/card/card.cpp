#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int cnt[500005];
int last[500005];
vector<int>ans[500005],now[500005];
void dfs(int t){
	
	cnt[a[t]]++;
	
	if(t>=n)return;
	
	if(ans[t].size()){
		for(int i=ans[t].size();i>0;i--){
			cnt[i]+=ans[t][i-1];
		}
		return;
	}
	for(int i=1;i<=m;i++){
		now[t].push_back(cnt[i]);
	}
	
	if(last[a[t]]){
		dfs(last[a[t]]);
		cnt[a[t]]--;
	}else{
		dfs(t+1);
	}
	for(int i=1;i<=m;i++){
		ans[t].push_back(cnt[i]-now[t][i-1]);
	}
	return;
}
signed main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);


	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		if(n!=i)last[a[i+1]]=i+1;
		
		
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}

	return 0;
}
/*
rp++;
rp++;
rp++;
*/
