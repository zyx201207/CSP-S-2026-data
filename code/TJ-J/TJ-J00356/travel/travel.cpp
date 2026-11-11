#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,z1,z2;
	int c1,c2;
	char a1,a2;
	cin>>c1>>s1>>c2>>s2;
	a1=s1[2];
	a2=s2[2];
	z1=s1[0]+s1[1];
	z2=s2[0]+s2[1];
	
	if(c1==c2){
		cout<<1;
	}else cout<<0;
	
	if(c1==c2&&z1==z2){
		cout<<1;
	}else cout<<0;
	
	if(c1==c2&&z1==z2&&('A'<=a1&&'C'>=a1)&&('A'<=a2&&'C'>=a2)){
		cout<<1;
	}else if(c1==c2&&z1==z2&&('D'<=a1&&'F'>=a1)&&('D'<=a2&&'F'>=a2)){
		cout<<1;
	}else cout<<0;
	
	if(c1==c2&&z1==z2&&('A'<=a1&&'C'>=a1)&&('A'<=a2&&'C'>=a2)&&(a1-1==a2||a1+1==a2)){
		cout<<1;
	}else if(c1==c2&&z1==z2&&('A'<=a1&&'C'>=a1)&&('A'<=a2&&'C'>=a2)&&(a1-1==a2||a1+1==a2)){
		cout<<1;
	}else cout<<0;

	return 0;
}
