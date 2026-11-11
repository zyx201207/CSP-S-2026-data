#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[6],s2[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1=(s1[0]-'0')*10+(s1[1]-'0');
	int a2=(s2[0]-'0')*10+(s2[1]-'0');
	int b1=s1[2]-'A';
	int b2=s2[2]-'A';
	if(b1==5) b1-=1;
	if(b2==5) b2-=1;
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if(b1<3&&b2<3||b1>2&&b2>2){
				cout<<1;
				if(b1-b2==1||b2-b1==1){
					cout<<1;
				}else{
					cout<<0;
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
}
