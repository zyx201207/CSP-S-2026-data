#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long m,a[500005],b[500005];
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
		int l=1,r=n-i+1;
		while(l<r){
			int mid=(l+r+1)/2;
			long long s=a[i+mid-1]*mid-b[i+mid-1]+b[i-1];
			if(s>m)
			    r=mid-1;
			else
			    l=mid;
		}
		ans=max(ans,l);
	}
	printf("%d\n",ans);
	return 0;
}
