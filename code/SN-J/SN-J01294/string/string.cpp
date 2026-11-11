//SN-J01294
#include<bits/stdc++.h>
using namespace std;
unsigned long long n,ans=0,a[200005],gcd=0;
string s1[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s1[i];
	}
	gcd=__gcd(a[1],a[2]);
	for(int i=3;i<=n;i++){
		gcd=__gcd(gcd,a[i]);
	}
	for(int i=1;i<=n;i++){
		int noww=a[i]/gcd;
		while(noww--){
			s+=s1[i];
		}
	}
	for(unsigned long long i=0;i<s.size()/2;i++){
		if(s[i]==s[s.size()-1-i]){
			continue;
		}
		ans++;
	}
	cout<<(unsigned long long)ans*gcd;
	return 0;
}
