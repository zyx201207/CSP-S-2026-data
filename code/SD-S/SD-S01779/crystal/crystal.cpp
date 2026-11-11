#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[100010*4],cha[100010*4],m,mn,jk,k,h,sum[100010*4],chb[100010*4],r=1,l=1e9,x;
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&k);
		a[i]=k;
		cha[i]=a[i]-a[i-1];	
	}
	sort(a+1,a+1+n);
		
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		chb[i]=a[i]-a[i-1];
		sum[i]+=a[i];
			
	}
	sort(chb+1,chb+n+1);
	
	for(int j=0;j<=m;j++){
		x=a[j]*j-sum[j-1];
		
		
	if(x>m)	{
	jk=j;
	break;
}
	}
	ans=jk;
	
	for(int op=jk;op>=0;op--){
	for(int i=ans-1;i<=n;i++){
	k=0;
	mn=sum[i]*ans-sum[i-ans];
	while(k<ans){
     mn-=a[i-ans+k]*(ans-k);
	k++;
	if(mn<=m)break;
	
}

    if(mn<=m)break;
}
  if(mn<=m)break;
  ans--;
  if(op==0)ans=0;
}

	
		printf("%lld",ans);
	return 0;
} 
