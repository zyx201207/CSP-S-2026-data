#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		long long p1=0,p2=0;
		p1=s1[0]*10+s1[1];
		p2=s2[0]*10+s2[1];
		if(p1==p2){
			int z1=s1[2]-int('A'),z2=s2[2]-int('A');
			if((z1<3&&z2<3)||(z1>2&&z2>2)){
				if(z2-z1==1){
					cout<<"1111"; 
				}
				else {
					cout<<"1110";
				}
			} 
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	return 0;
}
