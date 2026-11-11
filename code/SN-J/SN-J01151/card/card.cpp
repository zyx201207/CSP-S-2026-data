#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500002];
vector<int> mp[500001];
int las[500001],lass[500001];
int tot;
int w[500001],s[500001];
int n,m;
void dfs(int x){
	for(int i:mp[x]){
		dfs(i);
		s[x]+=s[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	tot=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		las[i]=lass[a[i]];
		lass[a[i]]=i;
	}
	w[0]=1;
	for(int i=n;i>=1;i--){
		
		if(!las[i]){
			w[a[i]]=++tot;
			mp[w[a[i+1]]].push_back(tot);
			s[tot]=1;
		}else{
			s[w[a[i]]]++;
		}
	}
	dfs(1);
	for(int i=1;i<=m;i++){
		cout<<s[w[i]]<<' ';
	} 
	return 0;
}
