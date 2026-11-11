#include<bits/stdc++.h>
using namespace std;
int main(){freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool flag=0;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	} 
	else{
		string n=s1.substr(0,2);
		string a=s2.substr(0,2);
		if(n!=a){
			cout<<"1000";
			return 0;
		}
		else{
			string n=s1.substr(2);
			string a=s2.substr(2);
			if(n=="A"||n=="B"||n=="C"){
				if(a!="A"&&a!="B"&&a!="C"){
					cout<<"1100";
					return 0;
				}
				flag=1;
			}
			else if(n=="D"||n=="F"){
				if(a!="D"&&a!="F"){
					cout<<"1100";
					return 0;
				}
				flag=1;
			}
			if(flag==1){
				if(a=="A"&&n=="B"){
					cout<<"1111";
					return 0;
				}
				if(a=="B"&&n=="A"){
					cout<<"1111";
					return 0;
				}
				if(a=="B"&&n=="C"){
					cout<<"1111";
					return 0;
				}
				if(a=="C"&&n=="B"){
					cout<<"1111";
					return 0;
				}
				if(a=="D"&&n=="F"){
					cout<<"1111";
					return 0;
				}
				if(a=="F"&&n=="D"){
					cout<<"1111";
					return 0;
				}
				
			}
			
		}
	}cout<<"1110";
	return 0;
}

