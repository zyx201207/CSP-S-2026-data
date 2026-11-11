#include<bits/stdc++.h> 
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	a=s2[2];
	b=s4[2];
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
		if(65<=a&&a<=67){
			c=1;
		}
		else{
			c=0;
		}
		if(65<=b&&b<=67){
			d=1;
		}
		else{
			d=0;
		}
		if(c==d){
			cout<<1;
			if(b-a==1||b-a==-1){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"000";
	}
	return 0;
}
