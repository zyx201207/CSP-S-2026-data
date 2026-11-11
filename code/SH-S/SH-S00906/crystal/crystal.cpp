#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N],n,m,s[N];
bool check(int li,int ri)
{
	ll sum=s[ri]-s[li-1];
	ll need=a[ri]*(ri-li+1)-sum;
	if(need>m) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i,res=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid,i)){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		if(i-res+1>ans){
			ans=i-res+1;
		}
	}
	cout<<ans;
	return 0;
 } 
