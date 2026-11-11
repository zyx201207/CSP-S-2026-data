#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m,Cost,ans=1,a[N];
signed main(){
	//张竞兮 冷静下来 我相信你 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2,j=1;i<=n;i++){
		Cost+=(a[i]-a[i-1])*(i-j);
		while(j<i&&Cost>m){Cost-=a[i]-a[j];j++;}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
