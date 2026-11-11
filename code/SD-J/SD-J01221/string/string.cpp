#include<bits/stdc++.h>
using namespace std;
long long T;
long long a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&a);
		cin>>c;
		for(long long i=1;i<=a;i++){
			s+=c;
		}
		
	}
	long long cnt=0;
	long long len=s.size();
	for(long long i=0,j=len-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
}
