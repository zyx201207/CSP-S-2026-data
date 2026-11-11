#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,siz,le[200005];
struct node{
	int len;
	char ch;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].len);
		le[i]=siz+1;
		siz+=a[i].len;
		cin>>a[i].ch;
	}
	le[n+1]=siz+1;
	int sum=0;
	for(int i=1;i<=n;i++){
		int l=le[i],r=le[i]+a[i].len-1;
		if(l>(siz+1)/2)break;
		int rr=siz-l+1,ll=siz-r+1;
		bool flag=0;
		if(ll<=r){
			flag=1;
			r=ll=(siz+1)/2;
		}
		int lid=lower_bound(le+1,le+n+1,ll)-le;
		int rid=lower_bound(le+1,le+n+1,rr)-le;
		if(ll<le[lid])lid--;
		if(rr<le[rid])rid--;
		if(lid==rid && a[i].ch!=a[lid].ch){
			sum+=(rr-ll+1);
		}
		else{
			if(a[lid].ch!=a[i].ch && lid<=n)sum+=(le[lid]+a[lid].len-ll);
			if(a[rid].ch!=a[i].ch && rid<=n)sum+=(rr-le[rid]+1);
			for(int j=lid+1;j<rid;j++)
			  if(a[j].ch!=a[i].ch)
		        sum+=a[j].len;
		}
		if(flag==1)break;
	}
	printf("%lld",sum);
	return 0;
}
