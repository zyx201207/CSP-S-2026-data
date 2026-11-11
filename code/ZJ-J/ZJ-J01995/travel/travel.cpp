#include<bits/stdc++.h>
#define ll long long
using namespace std;
string xc,xh,rc,rh;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rh>>xc>>xh;
	if(rc!=xc){
		cout<<"0000";
	}
	else{
		cout<<"1";
		string s1=rh.substr(0,2);
		string s2=xh.substr(0,2);
		if(s1!=s2){
			cout<<"000";
		}
		else{
			cout<<"1";
			char s3=rh[2],s4=xh[2];
			if((s3<'D'&&s4>'C')||(s3>'C'&&s4<'D')){
				cout<<"00";
			}
			else{
				cout<<"1";
				ll s5=s3-'A',s6=s4-'A';
				if(s5-s6!=1&&s5-s6!=-1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
		}
	}
	return 0;
}
