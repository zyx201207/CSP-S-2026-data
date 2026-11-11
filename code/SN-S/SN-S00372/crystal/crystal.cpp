//姓名：刘烨 考点：西北工业大学附属中学 学校：西安交通大学附属中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;

int n,m,a[N],s[N],ans;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	printf("%lld",ans);
	return 0;
}
