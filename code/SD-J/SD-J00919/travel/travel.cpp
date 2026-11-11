#include <bits/stdc++.h>
using namespace std;
string a1,b1,c1,d1,e1,a2,b2,c2,d2,e2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>c1>>d1;
	
	
	if(a1!=c1)cout<<"0000";
	else{
		if(b1[0]!=d1[0]||b1[1]!=d1[1])cout<<"1000";
		else{
			if(b1[2]>='A'&&b1[2]<='C'&&d1[2]>='A'&&d1[2]<='C'||b1[2]=='D'&&d1[2]=='F'||b1[2]=='F'&&d1[2]=='D'){
				if(b1[2]=='A'&&d1[2]=='C'||b1[2]=='C'&&d1[2]=='A'){
					cout<<"1110";
				}
				else cout<<"1111";
			}else{
				cout<<"1100";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
