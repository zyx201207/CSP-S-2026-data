#include <bits/stdc++.h>
#define int long long
//#define MOD (1000000007)
//#define eps (1e-6)
#define debug cout<<"debug"<<endl;
#define endl '\n'
using namespace std;
const int MAXN=5e5+10;
int n,m,a[MAXN],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,sum=0;
	for(int i=1;i<=n;++i){
		if(i!=1) sum+=(i-l)*(a[i]-a[i-1]);
		while(l<=i&&sum>m){
			sum-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
/*
uid:511811
得得得得 
和一位 
*/
