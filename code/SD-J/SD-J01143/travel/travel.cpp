#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string q,c;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-'0')*10+s1[1]-'0';
	b=(s2[0]-'0')*10+s2[1]-'0';
	q=s1[2];
	c=s2[2];
	if(c1==c2){
		cout<<1;
		if(a==b){
			cout<<1;
			if(q>="A"&&q<="C"&&c>="A"&&c<="C"){
				cout<<1;
				if((q=="A"&&c=="B")||(q=="B"&&c=="A")||(q=="B"&&c=="C")||(q=="C"&&c=="B")){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((q=="D"&&c=="F")||(q=="F"&&c=="D")){
				cout<<11;
			}else{
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
	return 0;
} 
