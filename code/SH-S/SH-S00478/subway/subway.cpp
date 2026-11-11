#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll m;
int main(){
	//freopen("subway.in","r",stdin);
	string x;
	cin>>x;
	string s="subway";
	if(x[0]!=0){
		s+=x;
		s+=(string)".out";
	}
	char* str;
	for(int i=0;i<s.size();i++){
		str[i]=s[i];
	}
	freopen(str,"r",stdin);
	freopen("subway.out","w",stdout);
	
	return 0;
} 
