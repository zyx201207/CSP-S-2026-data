#include <bits/stdc++.h>
#define INF (0x7FFFFFFF)
#define LL_INF (4e18)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=5e5+50;
ll a[N],pre[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0); 
	int n;
	ll m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	pre[0]=0;
	for (int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int l=0,ans=0;
	for (int r=1;r<=n;r++){
		while (1ll*(r-l)*a[r]-(pre[r]-pre[l])>m){
			l++;
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}

