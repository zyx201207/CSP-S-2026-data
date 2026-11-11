#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=5e5+7;
ll a[MAXN];
int n; ll m;
ll pre[MAXN];
inline bool check(int l,int r){
	return 1ll*a[r]*(r-l+1)-1ll*pre[r]+pre[l-1]<=m;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mid;
		while(l<r){
			int mid=l+r>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		while(l>1&&check(l-1,i)) l--;
		while(l<i&&!check(l,i)) l++;
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
} 