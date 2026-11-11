#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int x[200005];
char c[200005];
long long cnt;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&x[i],&c[i]);	
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			s+=c[i];
		}
	}
	long long len=s.size()-1;
	for(long long i=0;i<=len/2;i++){
		if(s[i]!=s[len-i]) cnt++;
	}
	printf("%lld",cnt);
	return 0; 
}
