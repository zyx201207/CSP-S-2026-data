#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
	cout<<"0000";
	return 0;
	}
	else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			char z1=s1[2];
			char z2=s2[2];
			if(z1=='F'&&z2=='D'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='D'&&z2=='F'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='A'&&z2=='B'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='B'&&z2=='A'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='C'&&z2=='B'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='B'&&z2=='C'){
				cout<<"1111";
				return 0;
			}
			else if(z1=='C'&&z2=='A'){
				cout<<"1110";
				return 0;
			}
			else if(z1=='A'&&z2=='C'){
				cout<<"1110";
				return 0;
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
			}	
	}
	return 0;
	}
