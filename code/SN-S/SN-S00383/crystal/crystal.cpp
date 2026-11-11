#include<bits/stdc++.h>
#define int long long 
#define O1145 ios::sync_with_stdio(false);
#define O1919 cin.tie(0),cout.tie(0);
using namespace std;
const int N=5e5+5;
int n,m,a[N],q[N];
signed main(){
	O1145 O1919
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int v=a[i];
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid+1)*v-(q[i]-q[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(i-(r+1)+1));
	}
	cout<<ans<<endl;
	return 0;
}
