#include<bits/stdc++.h>
using namespace std;
string cx,sx,cy,sy;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>sx>>cy>>sy;
	if(cx==cy&&cx!="01"&&cx!="16"){
		cout<<1;
		if(sx[0]==sy[0]&&sx[1]==sy[1]){
			cout<<1;
				if(sx[2]-sy[2]==1||sx[2]-sy[2]==-1){
					if((sx[2]=='C'&&sy[2]=='D')||(sy[2]=='C'&&sx[2]=='D')){
						cout<<0<<0;
					}
					else cout<<11;
				}else{
					if((sx[2]=='D'&&sy[2]=='F')||(sy[2]=='D'&&sx[2]=='F'))
					cout<<11;
					else if((sx[2]=='A'&&sy[2]=='C')||(sy[2]=='A'&&sx[2]=='C')) cout<<10;
						else{
						cout<<0<<0;
						}
				}
		}
		else
		cout<<0<<0<<0;
		
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
