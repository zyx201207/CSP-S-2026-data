#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],k=1,ans;
char c[200010],l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf("%s",&c[i]);
	}
	long long ri=a[n],le=1,rig=n,leg=1;
	while(rig>leg){
		if(c[leg]!=c[rig]){
			ans=ans+min(a[leg]-le+1,ri);
		}
		if(a[leg]-le+1>ri){
			rig--;
			le=le+ri;
			ri=a[rig];
			
		}else if(a[leg]-le+1==ri){
			rig--;
			ri=a[rig];
			leg++;
			le=1;
		}else{
			ri=ri-a[leg]+le-1;
			leg++;
			le=1;
			
		}
			
	}
	printf("%lld",ans);
	return 0;
}