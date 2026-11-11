#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,lt,rt,mid,ans,maxs;
int a[N],f[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(1+a,1+a+n);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		lt=1;rt=i;
		ans=-1;
		while(lt<=rt){
			mid=(lt+rt)>>1;
			if(a[i]*(i-mid+1)-(f[i]-f[mid-1])>m) lt=mid+1;
			else rt=mid-1,ans=mid;
		}
		if(ans==-1) continue;
		maxs=max(maxs,i-ans+1);
	}
	cout<<maxs;
	return 0;
}