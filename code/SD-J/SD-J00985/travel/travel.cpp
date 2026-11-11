#include<bits/stdc++.h>
using namespace std;
	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	long long cc1=(c1[0]-'0')*10+(c1[1]-'0');
	long long cc2=(c2[0]-'0')*10+(c2[1]-'0');
	long long ss1=(s1[0]-'0')*10+(s1[1]-'0');
	long long ss2=(s2[0]-'0')*10+(s2[1]-'0');
	if(cc1==cc2){
		cout<<"1";
		if(ss1==ss2){
			cout<<"1";
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<"1";
				if(s1[2]=='A'){
					if(s2[2]=='B'){
						cout<<"1";
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}else if(s1[2]=='B'){
					cout<<"1";
					return 0;				
				}else {
					if(s2[2]=='B'){
						cout<<"1";
						return 0;
					}else{
						cout<<0;
						return 0;
					}
				}
			}else if((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
