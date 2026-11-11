#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,ans,sum;
ll m,k=1;
bool f;
char s;
char c[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&m,&s);
		for(int j=k;j<k+m;j++){
			c[j]=s;
		}
		k+=m;
	}
	if(n==1){
		printf("%d",0);
		return 0;
	}
	k-=1;
	if(k%2==0){
		f=1;
	}else{
		f=0;
	}
	ll mid=(k+1)/2;
	if(f){
		for(int i=mid+1;i<=k;i++){
			if(c[i]!=c[k-i+1])ans++;
		}
		for(int i=mid;i>=1;i--){
			if(c[i]!=c[k-i+1])sum++;
		}
	}else{
		for(int i=mid+1;i<=k;i++){
			if(c[i]!=c[k-i+1])ans++;
		}
		for(int i=mid-1;i>=1;i--){
			if(c[i]!=c[k-i+1])sum++;
		}
	}
	printf("%lld",min(ans,sum));
	return 0;
}
