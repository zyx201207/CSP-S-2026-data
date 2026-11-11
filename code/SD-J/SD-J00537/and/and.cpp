#include<bits/stdc++.h>
using namespace std;
unsigned int v[200010];
int n,m;
int main(){
	ios::sync_with_stdio(nullptr);
	cin.tie(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	sort(v+1,v+n+1,greater<int>());
	unsigned int ans=INT_MAX;
	for(int i=1;i<=m;i++){
		ans&=v[i];
	}
	cout<<ans;
	return 0; 
} 
