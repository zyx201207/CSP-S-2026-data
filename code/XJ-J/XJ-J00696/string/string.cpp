#include <bits/stdc++.h>
using namespace std;
bool ishui(string str){
	if(str.substr(0,str.size()/2)==str.substr(str.size()/2,str.size()/2)) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	string str;
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long j;
		char c;
		cin>>j>>c;
		str+=j*c;
	}
	if(ishui(str)){
		cout<<0;
		return 0;
	}
	else cout<<str.size()/2;
	return 0;
}