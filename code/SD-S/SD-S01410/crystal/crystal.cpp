#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
int n,ans;
ll m,a[N],s[N];
int find(int st,int ed,ll x){
	int l=st,r=ed,best=r+1;
	for(;l<=r;){
		int mid=l+r>>1;
		if((ll)(ed-mid+1)*(x)-(s[ed]-s[mid-1])<=m){
			r=mid-1;
			best=mid;
		}else{
			l=mid+1;
		}
	}
	return best;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int it=find(1,i,a[i]);
		ans=max(ans,i-it+1);
	}
	printf("%d",ans);
	return 0;
}
