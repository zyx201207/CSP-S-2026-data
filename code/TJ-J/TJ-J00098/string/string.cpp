#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
long long n,t;
char a;
string s="";
long long hui(string x){
	long long len=x.size()-1,cnt=0;
	for(long long i=0;i<=len/2;i++){
		if(x[i]!=x[len-i]) cnt++;
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>t>>a;
		for(long long j=0;j<t;j++){
			s+=a;
		}
	} 
	printf("%lld",hui(s));
	
	
	return 0;
} 
