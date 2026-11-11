#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
//const int N=1e5+5;
//Ô¼100·Ö 
using namespace std;
int rcar,xcar;
string rsit,xsit;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	CLOSE
	
	cin>>rcar>>rsit>>xcar>>xsit;
	if(rcar!=xcar){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(rsit[0]==xsit[0] && rsit[1]==xsit[1]){
			cout<<"1";
			if((rsit[2]>='A' && rsit[2]<='C' && xsit[2]>='A' && xsit[2]<='C')||(rsit[2]>='D' && rsit[2]<='F' && xsit[2]>='D' && xsit[2]<='F')){
				cout<<"1";
				if(max(rsit[2],xsit[2])-min(rsit[2],xsit[2])==1){
					cout<<"1";
				}
				else if((rsit[2]=='D' && xsit[2]=='F')||(xsit[2]=='D' && rsit[2]=='F')){
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
	return 0;
} 
