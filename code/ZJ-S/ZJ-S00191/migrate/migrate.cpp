#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],dx;
void work(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	dx=x[n]-x[n-1];
	if(2*dx>d||n<=2)cout<<0<<'\n';
	else cout<<n-3<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--)work();
	return 0;
}
//yaoxingchengshuangjingdaoyudechongyaotiaojian:
//lianzuodaoyujianqiahaoyouliangzuodaoyuketongguotabingdaodalingyizuo
//meishijianla,zuoA+dfs