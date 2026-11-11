#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,a[N],b[N],c[N],ans=1,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-ans;i++){
		long long len=1,sp=0;
		for(int j=i;j<n;j++){
			sp+=c[j]*len;
			if(sp<=m){
				ans=max(ans,len+1);
				len++;
			}else{
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
