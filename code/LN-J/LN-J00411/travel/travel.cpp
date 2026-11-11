#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string ax,bx;
	cin>>a>>ax>>b>>bx;
	//((ax[2]=='A'||ax[2]=='B'||ax[2]=='C')&&(bx[2]=='A'||bx[2]=='B'||bx[2]=='C'))||((ax[2]=='D'||ax[2]=='F')&&(bx[2]=='D'||bx[2]=='F'))
	if(a==b){
		cout<<'1';
		if(ax[0]==bx[0]&&ax[1]==bx[1]){
			cout<<'1';
			if(((ax[2]=='A'||ax[2]=='B'||ax[2]=='C')&&(bx[2]=='A'||bx[2]=='B'||bx[2]=='C'))||((ax[2]=='D'||ax[2]=='F')&&(bx[2]=='D'||bx[2]=='F'))){
				cout<<'1';
					if(ax[2]-bx[2]==1||ax[2]-bx[2]==-1){
						cout<<'1';
					}
					else{
						cout<<'0';
					}
			}
			else{
				cout<<'0'<<'0';
			}
		}
		else{
			cout<<'0'<<'0'<<'0';
		}
	}
	else{
		cout<<'0'<<'0'<<'0'<<'0';
	}
	
	//cout<<a<<ax<<b<<bx;
}






