#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[200005],cnt,gcd;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	gcd=a[1];
	for(long long i=2;i<=n;i++){
		gcd=__gcd(a[i],gcd);
	}
	for(long long i=1;i<=n;i++){
		a[i]/=gcd;
		for(int j=1;j<=a[i];j++){
			s+=ch[i];
		}
	}
	for(long long i=0,j=s.size()-1;i<=s.size()/2-1,j>=s.size()/2;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt*gcd;
	
	return 0;
}
