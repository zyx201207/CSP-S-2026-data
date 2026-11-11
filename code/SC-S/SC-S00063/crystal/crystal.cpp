#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define ld long double
#define db double
using namespace std;
const int N=5e5+5;
int n,m,a[N],st[N],L,R;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int w=0;
	L=1;R=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]&&i!=1){
			w+=(a[i]-a[i-1])*(R-L+1);
		}
		R++;
		while(L<R&&w>m){
			L++;
			w-=(a[R]-a[L]);
		}
		ans=max(ans,R-L+1);
	}
	cout<<ans<<'\n';
	return 0;
}