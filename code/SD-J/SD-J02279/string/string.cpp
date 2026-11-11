#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,len,sum;
char ch; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %c",&m,&ch);
		for(int j=0;j<m;j++){
			s=s+ch;
		}
		len+=m;
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			sum++;
		}
	}
	printf("%d",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
