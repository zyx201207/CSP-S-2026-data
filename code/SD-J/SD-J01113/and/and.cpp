#include<bits/stdc++.h>
using namespace std;
int n,m,tong[35],len;
long long x,y,a[200010],b[200010],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(int j=0;j<=30;j++){
			tong[j]+=(a[i]>>j)&1;
		}
	}
	for(int i=30;i>=0;i--){
		if(tong[i]>=m){
			x=1<<i;
			y=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((a[i]>>y)&1==1){
			b[++len]=a[i]&(x*2-1);
		}
	}
	sort(b+1,b+1+len);
	ans=b[len];
	for(int i=len;i>=len-m+1;i--) ans=ans&b[i];
	printf("%lld",ans);
	return 0; 
} 
