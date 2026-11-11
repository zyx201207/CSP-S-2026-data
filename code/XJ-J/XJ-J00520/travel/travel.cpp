#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		char a1=s1[0]+s1[1],a2=s2[0]+s2[1];
		if(a1!=a2){
			cout<<"1000";
			return 0;
		}
		else{
			char v1=s1[2],v2=s2[2];
			if(v1=='D'&&v2=='F' || v1=='F'&&v2=='D'){
				cout<<"1111";
				return 0;
			}
			else if(v1=='A'&&(v2=='B'||v2=='C')){
				if(v2=='B'){
					cout<<"1111";
					return 0;
				}
				else{
					cout<<"1110";
				}
			}
			else if(v2=='A'&&(v1=='B'||v1=='C')){
				if(v1=='B'){
					cout<<"1111";
					return 0;
				}
				else{
					cout<<"1110";
				}
			}
			else if(v1=='B' &&(v2=='A' || v2=='C')){
				cout<<"1111";
				return 0;
			}
			else if(v2=='B' &&(v1=='A' || v1=='C')){
				cout<<"1111";
				return 0;
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
	}
}