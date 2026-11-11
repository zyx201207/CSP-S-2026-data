#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;	
	}
	else{
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			if(s1[3]=='D'&&s2[3]=='C'){
				cout<<"1100"<<endl;
			}
			if(s1[3]=='C'&&s2[3]=='D'){
				cout<<"1100"<<endl;
			}
			else{
				if(s1[3]=='A'&&s2[3]=='B'){
					cout<<"1111"<<endl;
				}
				if(s1[3]=='B'&&s2[3]=='A'){
					cout<<"1111"<<endl;
				}
				if(s1[3]=='B'&&s2[3]=='C'){
					cout<<"1111"<<endl;
				}
				if(s1[3]=='C'&&s2[3]=='B'){
					cout<<"1111"<<endl;
				}
				if(s1[3]=='D'&&s2[3]=='F'){
					cout<<"1111"<<endl;
				}
				if(s1[3]=='F'&&s2[3]=='D'){
					cout<<"1111"<<endl;
				}
				else{
					cout<<"1110"<<endl;
				}
			}
			return 0;
		}
		else{
			cout<<"1000"<<endl;
		}
	}
	return 0;
}

