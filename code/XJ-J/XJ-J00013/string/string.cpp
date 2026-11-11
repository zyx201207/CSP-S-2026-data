#include<iostream>
#include<string>
using namespace std;
long long t,cnt; 
string s;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout); 
	cin>>t;
	while(t--){
		long long x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			s=s+y;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		int j=s.size()-1-i;
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
