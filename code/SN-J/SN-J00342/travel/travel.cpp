#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	string p="";
	string p2="",k="",k2="";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		for(int i=0;i<s1.size()-1;i++){
			p+=s1[i];
		}
		for(int i=0;i<s2.size()-1;i++){
			p2+=s2[i];
		}
		if(p==p2){
			cout<<"1";
			for(int i=0;i<s1.size();i++){
				k=s1[2];
			}
			for(int i=0;i<s2.size();i++){
				k2=s2[2];
			}
			if(k<="C"&&k2<="C"){
				cout<<"1";
				if(k=="A"&&k2=="B"||k=="B"&&k2=="C"||
					k=="B"&&k2=="A"||k=="C"&&k2=="B"){
						cout<<"1";
						return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
				
			}
			else if(k=="F"&&k2=="D"||k=="D"&&k2=="F"){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
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
