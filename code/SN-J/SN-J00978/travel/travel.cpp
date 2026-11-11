#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traver.in","r",stdin);
	freopen("traver.out","w",stdout);
	int c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1 and c2!=1||16){
		
		cout<<1;
	
	}
	else cout<<0;
	if (s1%10==s2%10){
		cout<<1;
	}
	else cout<<0;
	if(c1!=c2){
		cout<<0000;
	}
	
	return 0;
}
