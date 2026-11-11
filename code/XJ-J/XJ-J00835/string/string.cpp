#include <bits/stdc++.h>
using namespace std;
long long n,len=0;
long long ans=0;
string s,x,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char b;
		cin>>a>>b;
		for(long long i=0;i<a;i++){
			s+=b;
		}
		len+=a;
	}
	string t=s;
	if(len%2==0){
		for(long long i=0;i<len/2;i++){
			x+=s[i];
		}
		for(long long i=len/2;i<len;i++){
			y+=s[i];
		}
		reverse(y.begin(),y.end());
		for(long long i=0;i<len/2;i++){
			if(x[i]!=y[i]){
				ans++;
			}
		}
	}
	else{
		for(long long i=0;i<len/2;i++){
			x+=s[i];
		}
		for(long long i=len/2+1;i<len;i++){
			y+=s[i];
		}
		reverse(y.begin(),y.end());
		for(long long i=0;i<len/2;i++){
			if(x[i]!=y[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}