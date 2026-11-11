#include<bits/stdc++.h>
using namespace std;
int n,ans;
const int N=5e5+10;
long long m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,p=i;
		while(l<=r){
			int mid=l+r>>1;
			if(1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1])<=m) p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}