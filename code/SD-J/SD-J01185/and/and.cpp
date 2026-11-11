#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,maxl;
vector<int> fk;
void dfs(int idx,int tot){
	if(tot==m){
		int tnt=fk[0];
		for(int i=1;i<m;i++)tnt&=fk[i];
		maxl=max(maxl,tnt);
		return;
	}
	if(n-idx+1<m-tot)return;
	if(idx>n)return;
	if(n-idx+1==m-tot){
		int l=fk.size();
		int tnt=fk[0];
		for(int i=1;i<tot;i++)tnt&=fk[i];
		for(int i=idx;i<=n;i++)tnt&=a[i];
		maxl=max(maxl,tnt);
		return;
	}
	fk.push_back(a[idx]);
	dfs(idx+1,tot+1);
	fk.pop_back();
	dfs(idx+1,tot);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==m&&a[1]==0){
		cout<<0;
		return 0;
	}
	if(m==1){
		cout<<a[n];
		return 0;
	}
	dfs(1,0);
	cout<<maxl;
	return 0;
}
