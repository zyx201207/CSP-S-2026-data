#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string d1,d2;
		d1=s1[0]+s1[1];
		d2=s2[0]+s2[1];
		if(d1==d2){
			cout<<1;
			string f1;
			string f2;
			f1=s1[2];
			f2=s2[2];
			if(f1=="A"){
				if(f2=="B") {
					cout<<"11";
				}else if(f2=="C"){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else if(f1=="B"){
				if(f2=="A"||f2=="C") cout<<"11";
				else cout<<"00";
			}else if(f1=="C"){
				if(f2=="B") {
					cout<<"11";
				}else if(f2=="A"){
					cout<<"10";
				}else{
					cout<<"00";
				}
			}else if(f1=="D"){
				if(f2=="F") cout<<"11";
				else cout<<"00";
			}else if(f1=="F"){
				if(f2=="D") cout<<"11";
				else cout<<"00";
			}
		}else {
			cout<<"000";
		} 
	}else{
		cout<<"0000";
	}
	return 0;
}
