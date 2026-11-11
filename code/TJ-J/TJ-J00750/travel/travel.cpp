#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	string j;
	string x;
	cin>>c1>>s1;
	cin>>j;
	cin>>c2>>s2;
	cin>>x;
	if(c1==c2)
	{
		cout<<"1";
		if(s1==s2){
			cout<<"1";
			if((j[0]>='A'&&j[0]<='C')&&(x[0]>='A'&&x[0]<='C')||(((j[0]=='F')&&(x[0]=='D'))||((j[0]=='D')&&(x[0]=='F')))){
				cout<<"1";
				if(x[0]+1==j[0]||j[0]+1==x[0]){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			} 
			else{
				cout<<"0";
				cout<<"0";
			} 
		}
		else{
			cout<<"0";
			cout<<"0";
			cout<<"0";
		}
	}
	else{
		cout<<"0"; 
		cout<<"0";
		cout<<"0";
		cout<<"0";
	}
	return 0;
} 
