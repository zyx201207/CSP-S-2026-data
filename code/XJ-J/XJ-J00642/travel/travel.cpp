#include<bits/stdc++.h>
using namespace std;

string a1,a2,b1,b2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<'1';
	else cout<<'0';
	
	string p1=a2.substr(0,2);//ее 
	string p2=b2.substr(0,2);
	if(a1==b1&&p1==p2) cout<<'1';
	else cout<<'0';
	
	bool is_left1=(a2[2]<='C');
	bool is_left2=(b2[2]<='C');
	
	if(a1==b1&&p1==p2&&is_left1==is_left2) cout<<'1';
	else cout<<'0';
	
	if(a1==b1&&p1==p2&&is_left1==is_left2&&abs(int(a2[2]-b2[2]))==1) cout<<'1';
	else cout<<'0';
	
	return 0;
}
