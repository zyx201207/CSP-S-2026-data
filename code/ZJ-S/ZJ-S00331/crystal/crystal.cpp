#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1,j=1;i<=n;i++){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans<<'\n';
	return 0;
}
//14.40