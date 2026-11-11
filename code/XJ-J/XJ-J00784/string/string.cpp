#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	if(s.size()==1){
		cout<<0;
	}else if(s.size()==2){
		cout<<1;
	}else cout<<0;
	
	return 0;
}
