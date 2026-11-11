#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in""r"stdin);
	freopen("travel.out""w"stdout);
	int c1,c2;
	char s1,s2;
	cin>>c1,s1,c2,s2;
	if(c1==c2||c1!=1&&c1!=16||c2!=1&&c2!=16){
		cout<<"1111";
	}else if(s1==s2){
			cout<<"1110";
	}else if('A'<=s1<='C'||'A'<=s2<='C'&&s1==s2=='D'&&s1==s2=='F'){
		cout<<"1110";	
		}
	return 0;
}
 
