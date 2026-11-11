#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans=1,l=1,tot;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		tot+=(a[i]-a[i-1])*(i-l);
		while(l<i&&tot>m){
			tot-=a[i]-a[l];
			l++;
		}
		ans=max(i-l+1,ans);
	}
	cout<<ans;
	/*本人一试提高组，T 1 卡了俩小时。
	  终于三改过样例，勿要爆0 了心事
	  另：再也不考提高组了，太难了T^T*/
}
