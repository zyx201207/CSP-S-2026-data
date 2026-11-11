#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin)
	freopen("string.out","w",stbout)
	string s;
	int n;
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]==n){
			cout<<2;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}