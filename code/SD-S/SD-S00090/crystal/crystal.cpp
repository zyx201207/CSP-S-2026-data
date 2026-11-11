#include<bits/stdc++.h>
using namespace std;
int m,n,ans;
long long a[500005],dif[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%lld",&a[i]);
	if(n>10000){
		int p=a[2]-a[1];
		long long sum=0;
		while(m-p*(sum)>=0){
		    m-=p*(sum);
			++sum;
		}
		printf("%lld",sum);
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	    dif[i]=a[i]-a[i-1];
	dif[1]=0;
	for(int i=1;i<=n;i++){
		int pre=0;
		for(int j=i;j<=n;j++){
			int now=pre+dif[j]*(j-i);
			pre=now;
			if(now<=m)
			    ans=max(ans,j-i+1);
		}
	}
	printf("%d",ans);
	return 0;
} 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7

1 5 17 21
  2 10 13
    4  6
       1
*/
