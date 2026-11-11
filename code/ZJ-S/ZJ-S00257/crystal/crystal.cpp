#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int inf=1e9+7;
const int N=5e5+5;
const int mod=998244353;
int n,ans;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		int l=1,r=i,pos=i;
		while(l<=r){
			int mid=(l+r)>>1;
			ll sum=a[i]*(i-mid+1)-(s[i]-s[mid-1]);
			//printf("sum:%d %d %lld\n",mid,i,sum);
			if(sum<=m) r=mid-1,pos=mid;
			else l=mid+1;
 		}
 		ans=max(ans,i-pos+1);
	}
	printf("%d\n",ans);
	return 0;
}