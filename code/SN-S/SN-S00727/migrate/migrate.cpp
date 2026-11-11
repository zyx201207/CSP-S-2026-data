#include<bits/stdc++.h>
#define N 2000005
#define mod 998244353
#define il inline
#define ll long long
using namespace std;
namespace xzz{
bool beg;
int T=1;
int n,lst[N],ans[N],f[N],g[N];
ll a[N],sum,d;
void newmain(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>a[i],ans[i]=f[i]=g[i]=0;
	for(int i=n;i>=1;i--){
		int tmp=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		lst[i]=tmp;
		if(i!=n){
			if(lst[i]+2<=lst[i+1])	g[i]=ans[i+1];
			else if(lst[i]+1==lst[i+1])	g[i]=g[lst[i]];
		}
		if(tmp==i)	continue;
		f[i]=f[tmp]+(tmp-i);
		if(tmp-1>i){
			int x=lst[tmp-1];
			if(x==lst[tmp])	f[i]=(tmp-i);
			else	f[i]-=(x-tmp);
		}
		if(lst[tmp]==tmp)	continue;
		if(i+1==tmp){ans[i]=ans[tmp];continue;}
		if(tmp-2>i&&lst[tmp-2]>=lst[tmp])	continue;
		if(lst[tmp-1]>=lst[tmp]){
			ans[i]=f[tmp]-(lst[tmp]-tmp);
			if(tmp-2>i)	ans[i]+=(lst[tmp]-lst[tmp-2]);
			else	ans[i]+=(lst[tmp]-tmp);
			continue;
		}
		if(tmp-2>i)	ans[i]=lst[tmp-1]-lst[tmp-2];
		else	ans[i]=lst[tmp-1]-tmp;
		if(lst[tmp-1]<lst[tmp]-1||lst[tmp-1]<=tmp)	ans[i]+=ans[tmp];
		else ans[i]+=g[lst[tmp]-1];
	}
	sum=0;
	for(int i=1;i<=n;i++)	sum+=ans[i];
	cout<<sum<<'\n';
}
bool ed;
void main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T>>T;
	while(T--)	newmain();
	return;
}
}
signed main(){xzz::main();return 0;}
