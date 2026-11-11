#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
  	int c1,c2;
  	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	while(c1<=17&&c2<=17){
		if(c1==c2){
			cout<<1;
			break;
		}
		else{
			cout<<0;
			break;
		}
	} 
	cout<<111;
	return 0; 
}
