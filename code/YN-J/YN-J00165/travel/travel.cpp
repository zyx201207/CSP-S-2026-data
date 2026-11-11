#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string d1,d2;
	char t1,t2;
	d1=s1[0]+s1[1];
	t1=s1[2];
	d2=s2[0]+s2[1];
	t2=s2[2];
	if(c1==c2){
		cout<<1;
		if(d1==d2){
			cout<<1;
			if(('A'<=t1&&t1<='C')&&('A'<=t2&&t2<='C')){
				cout<<1;
				if((t1+1==t2)||(t2+1==t1)){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((t1=='D'&&t2=='F')||(t2=='D'&&t1=='F')){
				cout<<"11";
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