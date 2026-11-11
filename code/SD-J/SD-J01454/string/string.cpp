#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	long long cnt=0;
	int i=1,k=n;
	while(i<=k){
		int t=a[i];
		for(int j=k;j>=i;j--){
			if(c[j]==c[i]){
				if(t>=a[j]) t-=a[j],a[j]=0;
				else a[j]-=t,t=0;
			} else{
				if(t>=a[j]) cnt+=a[j],t-=a[j],a[j]=0;
				else a[j]-=t,cnt+=t,t=0;
			}
			k=j;
			if(t==0) break;
		}
		i++;
	}
	printf("%lld",cnt);
	return 0;
} 
