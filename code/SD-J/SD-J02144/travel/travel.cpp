#include<bits/stdc++.H>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=10*c1[0]+c1[1];
	a2=10*c2[0]+c2[1];
	if(a1==a2){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<'1';
			char a=s1[2],b=s2[2];
			if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B')||(a=='A'&&b=='C')||(a=='C'&&b=='A')){
				cout<<'1';
				if((a=='D'&&b=='F')||(a=='F'&&b=='D')||(a=='A'&&b=='B')||(a=='B'&&b=='A')||(a=='B'&&b=='C')||(a=='C'&&b=='B'))
					cout<<'1';
				else
					cout<<'0';
			}
			else cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
