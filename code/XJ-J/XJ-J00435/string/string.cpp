#include<bits/stdc++.h>
using namespace std;
long long n,sum,a;
int s[90000010],cnt;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld %c",&a,&b);
		for(int j=1+sum;j<=sum+a;j++){
			s[i]=b;
		}
		sum+=a;
	}
	for(int i=1,j=sum;i!=j;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	printf("%d",cnt);
	return 0;
}