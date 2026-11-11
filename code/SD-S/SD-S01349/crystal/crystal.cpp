#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int lx=1,ans=1,s=1,sum=0;
	for(int i=2;i<=n;i++){
		sum+=s*(a[i]-a[i-1]);
		while(sum>m){
			sum-=a[i]-a[lx];
			lx++;
		}
		ans=max(ans,i-lx+1);
		s=i-lx+1;
		//cout<<i<<" "<<lx<<" "<<sum<<" "<<s<<"\n";
	}
	cout<<ans;
	return 0;
	//14:44
}
