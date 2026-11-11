#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){
	//取消注释 最后编译时间: 11:37:40-successful
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n=0;
	scanf("%lld",&n);
	string s;
	for(long long i=1;i<=n;i++){
		unsigned long long a=0;
		scanf("%lld",&a);
		char c='\0';
		cin>>c;
		for(unsigned long long i=1;i<=a;i++){
			s+=c;
		}
	}
	unsigned long long move=0;
	for(unsigned long long i=0;i<=s.length()/2;i++){
		if(s[i]!=s[s.length()-1-i]){
			move++;
		}
	}
	printf("%lld",move);
	
	return 0;
}
