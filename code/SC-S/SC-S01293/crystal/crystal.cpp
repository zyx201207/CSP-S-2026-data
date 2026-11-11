#include<iostream> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mx=5e5+100;
long long a[mx],m,d[mx],ans[mx];
int n,cnt=1;
long long _abs(long long x){return (x>=0)?(x):(-x);}
bool flag=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
		if(d[i]!=d[i-1]&&i>1) flag=0;
	}
	if(n>=10000&&flag) {
		if(d[1]!=0)printf("%lld",min(n,(int)(2*sqrt(m/d[1]))+1));
		if(d[1]==0) printf("%lld",n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=i;
		long long k=m;
		ans[i]=1;
		while(k>=0){
			if(cnt>=n) break;
			if(k>=ans[i]*d[cnt]){
				k-=ans[i]*d[cnt],ans[i]++,cnt++;
			}
			else break;
		}
	}
	sort(ans+1,ans+n+1);
	printf("%lld",ans[n]);
	return 0;
}