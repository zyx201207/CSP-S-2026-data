#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool z1=true,z2=true,z3=true,z4=true;
	if(c1==c2){
		//ÅÐ¶Ï1 
		int t1=0,t2=0;
		t1+=(s1[0]-'0')*10+(s1[1]-'0');
		t2+=(s2[0]-'0')*10+(s2[1]-'0');
		if(t1==t2){
			//ÅÐ¶Ï2 
			bool ce1,ce2;
			ce1=s1[2]-'A'<=2;
			ce2=s2[2]-'A'<=2;
			if(ce1==ce2){
				//ÅÐ¶Ï3 
				if(abs(s1[2]-s2[2])!=1) z4=false;
			}
			//·ñ3 
			else{
				z3=false;
			}
		}
		//·ñ2 
		else{
			z2=false;
		}
	}
	//·ñ1 
	else{
		z1=false;
	}
	if(z1) cout<<1;
	else{
		z2=false;
		z3=false;
		z4=false;
		cout<<0;
	}
	if(z2) cout<<1;
	else{
		z3=false;
		z4=false;
		cout<<0;
	}
	if(z3) cout<<1;
	else{
		z4=false;
		cout<<0;
	}
	if(z4) cout<<1;
	else{
		cout<<0;
	}
	return 0;
}
