#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define f(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
const int N=5e5+6;
int a[N];
int pre[N];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,k;cin>>n>>k;
	f(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);
	f(i,1,n)pre[i]=pre[i-1]+a[i];
	int ans=0;
	f(i,1,n){
		//cout<<a[i]<<" ";
		int l=1,r=i;
		int now=i;
		while(l<=r){
			int mid=(l+r)>>1;
			int nums=(i-mid+1)*a[i]-(pre[i]-pre[mid-1]);
			if(nums<=k){r=mid-1;now=mid;}
			else l=mid+1;
		}ans=max(ans,i-now+1);
		//cout<<i<<" "<<now<<"\n";
	}
	cout<<ans;
	return 0;
}