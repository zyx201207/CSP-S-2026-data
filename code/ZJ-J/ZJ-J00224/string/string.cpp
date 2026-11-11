#include<bits/stdc++.h>
using namespace std;
const long long M=1e9+10;
long long t,a,cnt,b;
string s,m,n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&t);
	for(int k=0;k<t;k++){
		scanf("%lld %s\n",&a,&s);
		b+=a;
		for(int i=0;i<a;i++){
			m=s+m;
		}
		n=m;
	}
	reverse(m.begin(),m.end());
	for(int j=0;j<b;j++){
		if(n[j]!=m[j]){
			cnt++;
		}
	}
	printf("%lld",cnt/2);		
	return 0;
}