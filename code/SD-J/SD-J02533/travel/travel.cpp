#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int b1,b2;
	b1=(s1[0]-'0')*10+(s1[1]-'0');
	b2=(s2[0]-'0')*10+(s2[1]-'0');
	char d1,d2;
	d1=s1[2];
	d2=s2[2];
	if(c1==c2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			if((('A'<=d1&&'C'>=d1)&&('A'<=d2&&'C'>=d2))||(('D'==d1||'F'==d1)&&('D'==d2||'F'==d2))){
				cout<<1;
				if(abs(d1-d2)==1){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
