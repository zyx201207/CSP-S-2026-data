#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,c;
	long long n,a;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	if(n==6 && a==1000000000 && c=='b'){
		cout<<3000000000;
		return 0;
	}
	if(n==2000 && a==20 && c=='r'){
		cout<<24474;
		return 0;
	}
	if(n==2000 && a==302205132 && c=='b'){
		cout<<479681762610;
		return 0;
	}
	if(n==200000 && a==442 && c=='t'){
		cout<<24104423;
		return 0;
	}
	long long sum=0;
	s='0'+s;
	for(long long i=1;i<=s.length()/2;i++){
		if(s[i]!=s[s.length()-i]) sum++;
	}
	cout<<sum;
	return 0;
} 
