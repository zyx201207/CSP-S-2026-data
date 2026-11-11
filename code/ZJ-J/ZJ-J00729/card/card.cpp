#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ls[300010],ans[300010],s[500010];
vector<int>v[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=1;
	}
	for(int i=n;i;--i){
		if(!ls[a[i]])v[i+1].push_back(i);
		else v[ls[a[i]]].push_back(i);
		ls[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j:v[i])s[i]+=s[j];
		ans[a[i]]=s[i];
	}
	for(int i=1;i<=m;++i)cout<<ans[i]<<" ";
	return 0;
}
