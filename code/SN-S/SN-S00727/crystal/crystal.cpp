#include<bits/stdc++.h>
#define N 500005
#define mod 998244353
#define il inline
#define ll long long
using namespace std;
namespace xzz{
bool beg;
int T=1;
int n,ans;
ll m,a[N],sum;
void newmain(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,l=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-l+1)-sum>m)	sum-=a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}
bool ed;
void main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(T--)	newmain();
	return;
}
}
signed main(){xzz::main();return 0;} 
