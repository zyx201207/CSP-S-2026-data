#include<iostream>
#include<cstdio>

using namespace std;
int n;
long long len=0;
string S;
long long a;
char c;
int main(){
	freopen("string6.in","r",stdin);
//	freopen("xxx.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %c",&a,&c);
		len+=a;
		for(;a>0;a--){
			S+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<(len%2==0?len/2:len/2+1);i++){
		if(S[i]!=S[len-i-1])ans++;
	}
	printf("%lld\n",ans);
	return 0;
}

