#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	long long l=0;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		l+=a[i];
	}
	long long sum=0;
	if(n==1)  printf("0");
	else if(n==2){
		if(c[1]==c[2])  printf("0");
		else  printf("%lld",min(a[1],a[2]));
	}
	else{
//		bool f=0;
//		long long cn1=0,cn2=0;
//		for(int i=1;i<=n/2;i++){
//			if(c[i]!=c[n+1-i])  sum+=max(a[i],a[n+1-i]);
//			else if(a[i]!=a[n+1-i]){
//				cn1=(max(a[i],a[n+1-i])-min(a[i],a[n+1-i]));
//				f=1;
//				cn2=max(a[i],a[n+1-i]);
//			}
//			if(f){
//				if(n%2==1||c[n/2]==c[n/2+1]) sum+=cn2;
//				else sum+=cn1;
//				f=0;     
//			}
//		}
		string s=" ";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++)  s+=c[i];
		}
		for(int i=1;i<=l/2;i++)  if(s[i]!=s[l+1-i])  sum++;
		printf("%lld",sum);
	}
	return 0;
}