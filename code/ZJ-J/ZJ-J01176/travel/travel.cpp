#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string ss1;
	ss1=s1[0]+s1[1];
	string ss2;
	ss2=s2[0]+s2[1];
	string xx1;
	xx1=s1[2];
	string xx2;
	xx2=s2[2];
	if(c1==c2){
		cout<<"1";
		if(ss1==ss2){
			cout<<"1";
			if(xx1=="D"&&xx2!="F"||xx1=="F"&&xx2!="D"||xx2=="D"&&xx1!="F"||xx2=="F"&&xx1!="D"){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(xx1=="A"&&xx2=="C"||xx1=="C"&&xx2=="A"){
					cout<<"0";
					return 0;
				}
				else{
					cout<<"1";
					return 0;
				}
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;

	
}