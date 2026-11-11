#include<bits/stdc++.h>
using namespace std;
char a[100000000],s2[100000];
int s[100000];
long long p,h;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	
	scanf("%d",&n);
	if(n==1) {
		printf("0");
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		scanf("%d %c",&s[i],&s2[i]);
	//	for(int j=1;j<=s[i];j++){
	//		a[i]=s2[i];
	//	}
	//	p=p+s[i];
	if(s2[i]==s2[i-1]) h++;
	}
	if(h==n) printf("%d",n);
	
	//for(int i=1;i<=p;i++){
	//	if(a[i]!=a[100000000-i+1]){
	//		h++;
	//	}
	//}
	//printf("%lld",h);
	return 0;
}
