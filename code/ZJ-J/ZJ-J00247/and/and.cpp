#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;vector<ll>a(n),b;
	for(ll&u:a)cin>>u;
	for(i=31;i>=0;i--){
		b.clear();
		for(ll u:a)
			if((u>>i)&1)b.push_back(u);
		if(b.size()>=m)a=b,p+=(1<<i);
	}
	cout<<p;
	return 0;
}
