#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define mid ((l+r)/2)
#define fop(i,l,r) for(int i=l;i<=r;i++)
int n,m,ans=0,a[500005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;fop(i,1,n)cin>>a[i];
	sort(a+1,a+1+n);for(int i=1;i<=n;i++){
		int temp=a[i];a[i]+=a[i-1];
		int l=1,r=i;while(l<=r){
			if(temp*(i-mid+1)-(a[i]-a[mid-1])<=m)r=mid-1;
			else l=mid+1;
		}ans=max(ans,i-r);
	}cout<<ans;return 0;
}