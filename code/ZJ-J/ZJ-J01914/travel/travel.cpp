#include<bits/stdc++.h>
using namespace std;
//const int N=1e5+5;
string c1,s1,c2,s2;
int f[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f['A'-64]=0;
	f['B'-64]=0;
	f['C'-64]=0;
	f['D'-64]=1;
	f['F'-64]=1;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char a=s1[2],b=s2[2];
			if(f[a-64]==f[b-64]){
				cout<<1;
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(b=='A'&&a=='B')||(b=='B'&&a=='C')||(a=='D'&&b=='F')||(a=='F'&&b=='D')){
					cout<<1;
				}
				else{
					cout<<0;
				}
				
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
