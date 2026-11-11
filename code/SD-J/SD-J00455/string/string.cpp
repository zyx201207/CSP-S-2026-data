#include<bits/stdc++.h>
using namespace std;
char s[1000000005],p[5];
long long n,a,sum=0,change=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		for(int k=1;k<=2;k++)
			scanf("%c",&p[k]);		
		for(int j=sum+1;j<=sum+a;j++)
			s[j]=p[2];
			sum=sum+a;
	}
	for(int i=1;i<=sum/2;i++)
		if(s[i]!=s[sum+1-i])
			change++;
	printf("%lld",change);
	return 0;
}
