#include<bits/stdc++.h>
using namespace std;
string b;
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	while(n--){
		long long c;
		char k;
		scanf("%lld %c",&c,&k);
		while(c--){
			b+=k;
		}
	}
	long long m=b.size()/2;
	for(int i=0;i<m;i++){
		if(b[i]!=b[b.size()-1-i]){
			ans++;
		}
	}
	printf("%lld",ans);
  	fclose(stdin);
	fclose(stdout);
}
