#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[5],b[5],c[5],d[5];
	cin>>a>>b>>c>>d;
	int xa=int(a[1]-'0')+int(a[0]-'0')*10;
	int xb=int(c[1]-'0')+int(a[0]-'0')*10;
	int ya=int(b[1]-'0')+int(b[0]-'0')*10;
	int yb=int(d[1]-'0')+int(d[0]-'0')*10;
	if(xa==xb){
		cout<<"1";
		if(ya==yb){
			cout<<"1";
			if(b[2]=='D'||d[2]=='D'||b[2]=='F'||d[2]=='F'){
				if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				cout<<"1";
				if(b[2]=='B'||d[2]=='B'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
}