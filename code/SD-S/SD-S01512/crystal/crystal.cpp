#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int pre[maxn],a[maxn];
int n,m;
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int fans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		int ans;
		while(l<=r){
			int mid=(l+r)/2;
			int now=pre[i-1]-pre[mid-1];
			if((i-mid)*a[i]-now<=m){
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		fans=max(fans,i-ans);
	}
	cout<<fans+1;	
	return 0;
}
