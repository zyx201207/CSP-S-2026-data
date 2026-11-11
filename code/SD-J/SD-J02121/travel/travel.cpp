#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
string c1,s1,c2,s2;
char p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	p1=s1[2];
	p2=s2[2];
	if(p1<p2){
		swap(p1,p2);
	}
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if((p1<='C' && p2<='C') || (p1>'C' && p2>'C')){
				cout<<"1";
				if(p1-p2==1 && (p1!='E' || p2!='D')){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	cout<<endl;
	return 0;
}
