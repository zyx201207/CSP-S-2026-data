#include<bits/stdc++.h>
using namespace std;
string f,r,c,y;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>f>>r>>c>>y;
	if(f==c){
		cout<<"1";
		if(r[0]+r[1]==y[0]+y[1]){
			cout<<"1";
			if(((r[2]=='A'||r[2]=='B'||r[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C'))||((r[2]=='D'||r[2]=='E')&&(y[2]=='D'||y[2]=='E'))){
				cout<<"1";
				if((r[2]=='A'&&y[2]=='B')||(r[2]=='B'&&y[2]=='A')||(r[2]=='B'&&y[2]=='C')||(y[2]=='B'&&r[2]=='C')||(r[2]=='D'&&y[2]=='E')||(y[2]=='D'&&r[2]=='E')){
					cout<<"1";
				}
				else{
					cout<<"0";
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
	return 0;
}
