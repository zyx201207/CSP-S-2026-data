#include<bits/stdc++.h>
using namespace std;
struct number{
	long long a;
	char c;
}s[20010];
int main(){
	long long n,zfsize=0,shuchu=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i+=1){
		cin>>s[i].a;
		cin>>s[i].c;
		zfsize+=s[i].a;
	}
	for(long long i=1;i<=zfsize/2;i+=1){
		long long zhizhen=0;
		char zfq;
		char zfh;
		long long h=1;
		while(zhizhen<i){
			zhizhen+=s[h].a;
			zfq=s[h].c;
			h+=1;
		}
		zhizhen=zfsize;
		h=1;
		while(zhizhen>zfsize-i){
			zhizhen-=s[zfsize-h].a;
			zfh=s[zfsize-h].c;
		}
		if(zfq!=zfh){
			shuchu+=1;
		}
	}
	cout<<shuchu;
	return 0;
}
