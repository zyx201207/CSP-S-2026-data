#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500010
int n,ans=1;ll m,a[N],res;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1){cout<<"1\n";return 0;}
	for(int i=2,j=1;i<=n;i++){
		res+=(a[i]-a[i-1])*(i-j);
		while(j<=i && res>m){res-=a[i]-a[j];j++;}
//		cout<<j<<' '<<i<<'\n';
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}