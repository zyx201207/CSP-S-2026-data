//O(nlogn)
//只增不减
//归于一点总是不劣的 
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m,a[maxn],b[maxn];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m)
				r=mid;
			else
				l=mid;
		}
//		cout<<i<<" "<<r<<endl;
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
}
