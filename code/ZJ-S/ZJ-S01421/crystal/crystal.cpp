#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,an=1,ans,x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;++i){
	    x+=an*(a[i]-a[i-1]);
		an++;
		if(x<=m){
			ans=max(ans,an);
	    }else{
	    	while(x>m){
	    		x-=a[i]-a[i-an+1];
	    		an--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
