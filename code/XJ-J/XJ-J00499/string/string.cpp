#include<bits/stdc++.h>
using namespace std;
long long n,sum;
string s;
int x(string s1,long long l){
	long long q=0;
	for(long long i=0;i<l/2;i++){
		
		if(s1[i]!=s1[(l-1)-i]){
			q++;
		}
	}
	return q;
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,lg=0;
	char a1;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++){
    	scanf("%lld",&a);
    	scanf("%c",&a1);
    	lg+=a;
    	for(long long j=0;j<a;j++){
    		s+=a1;
		} 
	}
    //printf("%lld",s);
    sum=x(s,lg);
	if(sum==0)printf("0");
	else printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}