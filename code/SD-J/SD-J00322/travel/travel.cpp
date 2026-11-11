#include<bits/stdc++.h>
using namespace std;
string s1,s2;
string c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char p1=s1[0]+s1[1];
	char p2=s2[0]+s2[1];
	char z1=s1[2];
	char z2=s2[2];
	if(c1==c2){
		cout<<1;
		if( p1==p2){
			cout<<1;
			if(('A'<=z1&&z1<='C'&&'A'<=z2&&z2<='C') || (('D'==z1||z1=='F')&&('D'==z2||z2=='F'))) {
				cout<<1;
				if((z1+1==z2 && z1!='C')||(z2+1==z1 && z2!='C') ||(z1=='D' && z2=='F') || (z1=='F' && z2=='D') ){
					cout<<1;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		} else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	} 
	return 0;
} 
