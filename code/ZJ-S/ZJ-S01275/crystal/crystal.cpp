#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],pre[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int p=a[1];
	for(int i=1;i<=n;i++){
		a[i]-=p;
	}
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
		int l=-1,r=i;
		while(l<r-1){
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-pre[i]+pre[mid-1]<=m){
				r=mid;
			}
			else{
				l=mid;
			}
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans;
	return 0;
}
