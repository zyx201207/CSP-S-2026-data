#include <bits/stdc++.h>
using namespace std;

 int main() {
 	freopen("travel.in","r",stdin);
 	freopen("travel.out","w",stdout);
 	
	int c1,c2;
 	int s1,s2;
 	char s3,s4;
 	cin>>c1>>s1>>s3>>c2>>s2>>s4;
 	
 	if(c1==c2) {
 		cout<<"1";
 		if(s1==s2) {
			cout<<"111";
 		} else {
	 		cout<<"000";
	 	}
	 } else {
	 	cout<<"0000";
	 }
	 	
	 	
 	return 0; 
 } 
