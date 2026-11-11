#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
long long m,sum,mid;
int c[200005];
int n,k,ans,d,e;
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]) k++,b[k]=a[i],c[k]=1;
		else c[k]++;
	}
	d=b[2]-b[1];
	e=c[1];
	if(c[2]!=e) f=true;
	else{
		for(int i=3;i<=k;i++){
			if(b[i]-b[i-1]!=d||c[i]!=e){
				f=true;
				break;
			}
		}
	}
	if(!f){
		m=m/d/e;
		int l=1,r=n;
		while(l<r){
			mid=(l+r+1)/2;
			if(mid*(mid-1)/2<=m) l=mid;
			else r=mid-1;
		}
		printf("%d",l);
		return 0;
	}
	for(int i=1;i<=k;i++){
		sum=d=0;
		for(int j=i+1;j<=k;j++){
			d+=c[j-1];
			sum+=(b[j]-b[j-1])*d;
			if(sum>m){
				ans=max(ans,d);
				break;
			}
		}
		if(sum<=m) ans=max(ans,d+c[k]);
	}
	printf("%d",ans);
	return 0;
}