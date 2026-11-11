#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cf2[33],mx,mi,ans;
vector<int>v1;
vector<int>v2;
void dfs(int d){
	if(d==-1)return ;
	for(int i=0;i<v1.size();++i){
		if(a[v1[i]]>=cf2[d]){
			a[v1[i]]-=cf2[d];
			v2.push_back(v1[i]);
		}
	}
	if(v2.size()<m){
		v2.clear();
		dfs(d-1);
		return ;
	}
	ans+=cf2[d];
	v1.clear();
	v1=v2;
	v2.clear();
	dfs(d-1);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cf2[0]=1;
	for(int i=1;i<=32;++i){
		cf2[i]=cf2[i-1]*2;
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		mx=max(mx,a[i]);
		v1.push_back(i);
	}
	if(mx==0){
		cout<<0;
		return 0;
	}
	for(int i=31;i>=0;--i){
		if(mx>=cf2[i]){
			mi=i;
			break;
		}
	}
	dfs(mi);
	cout<<ans;
	return 0;
}
