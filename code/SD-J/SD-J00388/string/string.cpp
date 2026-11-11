#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long k=1;k<=a;k++){
			s+=c;
		}
	}
	long long fori=s.size()/2;
	long long ans=0;
	for(long long i=1;i<=fori;i++){
		if(s[i]!=s[s.size()+1-i]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
} 
