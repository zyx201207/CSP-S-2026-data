#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	char a=s1[2],b1=s1[0],b2=s1[1];
	
	char n=s2[2],n1=s2[0],n2=s2[1];
	if(c1==c2){
		if(b1==n1&&b2==n2){
			if((n>'C' && a>'C') || (n<='C' && a<='C')){
				if(abs(a-n)==1){
					cout<<"1111";
				}
				else{
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
	else{
		cout<<"0000";
	}
	return 0;
}