#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<1;
		if(c2[0]==c4[0]&&c2[1]==c4[1]){
			cout<<1;
			if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c4[2]=='A'||c4[2]=='B'||c4[2]=='C')){
				cout<<1;
				int d2=c2[2]-'0',d4=c4[2]-'0';
				if(d2-1==d4||d2+1==d4){
					cout<<1;
				}
				else cout<<0;
			}
			else if((c2[2]=='D'||c2[2]=='F')&&(c4[2]=='D'||c4[2]=='F')){
				cout<<1;
				int d2=c2[2]-'0',d4=c4[2]-'0';
				if(d2-1==d4||d2+1==d4){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
