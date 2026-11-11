#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],pre[N];
inline bool chk(int i,int j){
	return pre[j-1]-j*a[i]<=m-a[i]*(i+1)+pre[i];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	

	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int j=i;
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(chk(i,mid))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);	
	}
	cout<<ans;
}
