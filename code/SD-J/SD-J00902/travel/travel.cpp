#include<bits/stdc++.h>
using namespace std;
bool a=false,b=false,c=false,d=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1){
		a=true;
		if(r2[0]==x2[0]&&r2[1]==x2[1]){
			b=true;
			if(r2[2]=='D'&&x2[2]=='F'){
				c=true;
				d=true;
			}if(r2[2]=='F'&&x2[2]=='D'){
					c=true;
				d=true;
			}if(r2[2]!='D'&&x2[2]!='D'&&r2[2]!='F'&&x2[2]!='F'&&abs((r2[2]-'0')-(x2[2]-'0'))<=2){
				c=true;
				if(r2[2]!='D'&&x2[2]!='D'&&r2[2]!='F'&&x2[2]!='F'&&abs((r2[2]-'0')-(x2[2]-'0'))<=1){
					d=true;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
