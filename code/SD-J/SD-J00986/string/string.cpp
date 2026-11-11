#include<iostream>
#define ll long long
using namespace std;
ll n,sum,ans,a[200005],a2[200005];
char c[200005],c2[200005];
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		if(c[i]==c[i-1])
			a2[sum]+=a[i];
		else
			a2[++sum]=a[i],c2[sum]=c[i];
	}
	if(sum==1){
		printf("0");
		return 0;
	}
	for(int i=1,j=sum;i<j;){
		ll tem=min(a2[i],a2[j]);
		if(c2[i]!=c2[j])
			ans+=tem;
		a2[i]-=tem,a2[j]-=tem;
		if(!a2[i])
			i++;
		if(!a2[j])
			j--;
	}
	printf("%lld",ans);
	return 0;
} 
