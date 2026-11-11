#include<iostream>
#include<cmath>
using namespace std;
int temp1,temp2;
string s1,s2,temps1,temps2;
char c1,c2;
bool flag1,flag2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>temp1>>temps1>>temp2>>temps2;
	c1=temps1[2];
	c2=temps2[2];
	s1=temps1.substr(0,2);
	s2=temps2.substr(0,2);
	//cout<<c1<<" "<<c2<<" "<<s1<<" "<<s2<<"\n";
	if(temp1==temp2){
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if(c1=='A'||c1=='B'||c1=='C'){
				flag1=0;
			}else{
				flag1=1;
			}
			if(c2=='A'||c2=='B'||c2=='C'){
				flag2=0;
			}else{
				flag2=1;
			}
			if(flag1==flag2){
				cout<<"1";
				if(abs(int(c1)-int(c2))==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
} 
