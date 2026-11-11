#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,res;
long long m,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(1ll*(i-mid+1)*a[i]-b[i]+b[mid-1]>1ll*m){
				l=mid+1;
			}else{
				r=mid-1;
				ans=mid;
			}
		} 	 		
		res=max(res,i-ans+1);
	}
	printf("%d",res);
	return 0;
}
