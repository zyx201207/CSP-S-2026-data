#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+8;
ll ans;
ll n,m;
ll ss[N];
ll dfs(ll i,ll x){
	if(i==m+1){
		return x;
	}ll cnt=0;
	for(int j=1;j<=n;j++){
		if(j!=i){
			cnt=max(cnt,dfs(i+1,x&ss[j]));
		}
		
	}
	return cnt;

}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ss[i];
	}cout<<dfs(0,pow(2,18)-1)/2+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
