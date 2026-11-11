// SN-J01021 Ê¦´ó01¿¼³¡  ³Â¼ÎÏé 
#include<bits/stdc++.h>
using namespace std;
string s;
long long n,m,a,cnt,tot;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>x;
		for(long long j=0;j<a;j++){
			s[m++]=x;
		}
	}
	long long l=0,r=m-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++;
		r--;
	}
	printf("%lld",cnt);
	return 0;
}
