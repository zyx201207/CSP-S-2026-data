#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans=-1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]); 
	}
	bool flag=1; 
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1])flag=0;
	}
	if(flag){
		printf("%lld",n);
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long cnt=0,count=0;
		for(int j=i;j<=n;j++){
			if(count+(j-i)*b[j]<=m){
				count+=(j-i)*b[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
