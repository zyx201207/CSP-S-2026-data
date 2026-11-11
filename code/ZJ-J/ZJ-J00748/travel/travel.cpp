#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f=0,l=0,a=0,g=0;
	if(c1==c2){
		f=1;
		char a1=s1[2],a2=s2[2];
		int z1,z2;
		z1=(s1[0]-48)*10+(s1[1]-48);
		z2=(s2[0]-48)*10+(s2[1]-48);
		if(z1==z2){
			l=1;
			if((a1=='A'&&a2=='B')||(a1=='B'&&a2=='C')||(a1=='D'&&a2=='F')||(a1=='B'&&a2=='A')||(a1=='C'&&a2=='B')||(a1=='F'&&a2=='D')){
				a=1;
				g=1;
			}
			if((a1=='A'&&a2=='C')||(a1=='C'&&a2=='A'))a=1;
		}
	}
	cout<<f<<l<<a<<g;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
