#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("reavel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string p1,p2;
	char z1,z2;
	for(int i=0;i<2;i++){
		p1+=s1[i];
		p2+=s2[i]; 
	}
	z1=s1[2];
	z2=s2[2];
	bool f1=0,f2=0,f3=0;
	if(c1==c2) f3=1,cout<<1;
	else cout<<0;
	
	if(p1==p2&&f3) f2=1,cout<<1;
	else cout<<0;
	
	if(z1<=67&&z2<=67||z1>67&&z2>67) f1=1;
	if(p1==p2&&f1&&f3) cout<<1;
	else cout<<0;
	
	if(abs(z1-z2)==1&&f1&&f2) cout<<1;
	else cout<<0;
	
	fclose(stdin);
	fclose(stdout);
} 
