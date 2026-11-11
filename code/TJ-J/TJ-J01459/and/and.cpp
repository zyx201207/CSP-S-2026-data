#include<bits/stdc++.h>
using namespace std;
int n,m,d,a[12345],maxn=0;
void dfs(int fir,int cho,int now){
	if(fir>n) return;
	if(cho==m){
		if(fir<=n){
			maxn=(maxn>now?maxn:now);
			return;
		}
		return;
	}
	dfs(fir+1,cho+1,now&a[fir+1]);
	dfs(fir+1,cho,now);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	if(n==m){
		int z=1;
		for(int i=1;i<=n;i++) z&=a[i];
		cout<<z;
		return 0;
	}
	for(int i=1;i<=31;i++) d*=2;
	d--;
	dfs(0,0,d);
	cout<<maxn;
	return 0;
}
