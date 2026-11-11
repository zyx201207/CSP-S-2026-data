#include<bits/stdc++.h>
#define ioi ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],dis[N],ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ioi;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) dis[i]=dis[i-1]+(a[i]-a[i-1])*(i-1);
	for(int i=n;i>=2;i--){
		for(int j=n;j>=i;j--){
			if(dis[j]-dis[j-i]<=m){
				ans=i;
				break;
			}
		}	
	}
	cout<<ans;
	return 0;
}