#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long ans=0;
	cin>>n;
	string str="";
	for(int i=1;i<=n;i++){
		long long cnt;
		char ch;
		cin>>cnt>>ch;
		for(long long j=1;j<=cnt;j++) str+=ch;
	}
	for(long long i=0;i<str.size()/2;i++){
		if(str[i]!=str[str.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
