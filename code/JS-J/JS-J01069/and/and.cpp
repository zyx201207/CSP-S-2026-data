#include<bits/stdc++.h>
using namespace std;
bitset<40> a[200001];
set<long long int> s[40];
int n,m,b[200001],x,t;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>b[i],a[i]=b[i];
	for(int j=1;j<=n;j++) s[31].insert(j);
	for(int i=30;i>=0;i--){
		for(auto q:s[i+1]) if(a[q][i]) s[i].insert(q);
		if(s[i].size()<m) s[i]=s[i+1];
	}
	x=2147483647,t=0;
	for(auto i:s[0]){
		x&=b[i];
		if(++t==m) break;
	}
	cout<<x;
	return 0;
}
