#include<bits/stdc++.h>
using namespace std;
long long c1,c2,p1,p2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>p1>>s1>>c2>>p2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else if(p1!=p2){
		cout<<"1000";
		return 0;
	}
	else{
		cout<<"11";
		if(s1!="D" && s1!="F"){
			if(s2!="D" && s2!="F"){
				cout<<"1";
				if(s1=="A" && s2=="B"){
					cout<<"1";
				}
				else if(s1=="B" && (s2=="A" || s2=="C")){
					cout<<"1";
					return 0;
				}
				else if(s1=="C" && s2=="B"){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}
		else if(s1=="D" || s1=="F"){
			if(s2=="D" || s2=="F"){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
	}
	return 0;
}
