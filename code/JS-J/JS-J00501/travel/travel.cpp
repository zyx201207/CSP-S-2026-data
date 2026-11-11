#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string a,b;
		a+=s1[0];
		a+=s1[1];
		b+=s2[0];
		b+=s2[1];
		// cout<<a<<" "<<b;
		if(a==b){
			cout<<"1";
			char p1,p2;
			p1=s1[2],p2=s2[2];
			if((p1=='C'&&p2=='D')||(p1=='D'&&p1=='C')){
				cout<<"00";
			}
			else{
				cout<<"1";
				if((p1=='D'&&p2=='F')||(p1=='F'&&p2=='D')){
					cout<<"1";
				}
				else if(abs(p1-p2)==1)cout<<"1";
				else cout<<"0";
			}
		}
		else{
			cout<<"000";
		}
	}
	else
		cout<<"0000";

	return 0;
}