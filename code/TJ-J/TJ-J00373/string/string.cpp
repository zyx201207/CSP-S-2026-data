#include<bits/stdc++.h>
using namespace std;
struct s{
	long long a;
	char c;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	scanf("%lld",&n); 
	long long cnt=0;
	for(int i=1;i<=n;i++){
		char c;
		scanf("%lld",&b[i].a);
		
		cin>>b[i].c;
		cnt+=b[i].a;
}
	long long ans=0;
	int cn=n;//当前处理到后面第几个的段了 
	for(int i=1;i<=n;i++){
		while(b[i].a!=0){
			if(b[i].c==b[cn].c){
				if(b[i].a>=b[cn].a){
					b[i].a-=b[cn].a;
					b[cn].a=0;
					cn--;
				}else{
					b[cn].a-=b[i].a;
					b[i].a=0;	
				}
			}else{
				if(b[i].a>=b[cn].a){
					b[i].a-=b[cn].a;
					ans+=b[cn].a;
					b[cn].a=0;
					cn--;
				}else{
					b[cn].a-=b[i].a;
					ans+=b[i].a;
					b[i].a=0;
					
			}
		}
	}
}
	cout<<ans;
	
	
	
	
	return 0;
} 
