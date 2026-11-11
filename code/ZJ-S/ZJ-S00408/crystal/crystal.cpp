#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7;
const int N=5e5+10;
auto getmax=[](auto &a,auto b){a=max(a,b);};
auto getmin=[](auto &a,auto b){a=min(a,b);};

ll n,m,a[N],s[N];
int ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) s[i]=s[i-1]+a[i];

	for(int i=1,j=1; i<=n; i++){
		while(j<=i&&a[i]*(i-j+1)-s[i]+s[j-1]>m) j++;
		getmax(ans,i-j+1);
	}
	cout<<ans;
	
	return 0;
}