#include<bits/stdc++.h>
using namespace std;
int main(){
	
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n
	long long a;
	char b;
	string s;
	long long qs=n,js=0;
	for(long long i=1;i<=n;i++){
		cin>>a>>b;
		for(long long j=1;j<=a;j++){
			s[j]=b;
		}
	}
	for(long long j=1;j<qs;j++){
		if(s[j]!=s[qs]){
			js++;
		}	
	}
	cout<<js;

}
