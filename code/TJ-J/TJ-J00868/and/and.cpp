#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll m,n,aaa[N];
ll dfs(ll pos,ll mm){
	if(mm==m || pos==n)return 0;
	ll mx=0;
	for(ll i=pos+1;i<=n;i++){
		ll val=dfs(i,mm+1);
		if(val==0ll)val=aaa[i];
		mx=max(mx,val&aaa[i] );
	}return mx;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>aaa[i];
	cout<<dfs(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
