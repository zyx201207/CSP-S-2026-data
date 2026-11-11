#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	string x1,y1;
	string x2,y2;

	cin>>x1>>y1;
	cin>>x2>>y2;
	if (x1[0]==y2[0] && x1[1]==x2[1]){
		cout<<1;
		if (y1[0]==y2[0] && y1[1]==y2[1]){
			cout<<1;
			if (y1[2]>='A' && y1[2]<='C' && y2[2]>='A' && y2[2]<='C'){
				cout<<1;
				if (abs(y1[2]-y2[2])==1 || y1[2]=='F' && y2[2]=='D'){
					cout<<1;				}
				else cout<<0;
			}
			else if(y1[2]>='D' && y1[2]<='F' && y2[2]>='D' && y2[2]<='F'){
				cout<<1;
				if (abs(y1[2]-y2[2])==1 || y1[2]=='F' && y2[2]=='D'){
					cout<<1;				}
				else cout<<0;
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
