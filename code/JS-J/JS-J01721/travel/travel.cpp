#include <bits/stdc++.h>
using namespace std;
//long long
//printf
//scanf
string c1,c2,c3,c4;
bool a=false,b=false,c=false,d=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
	    a=true;	
	    if(c2[0]==c4[0]&&c2[1]==c4[1]){
			b=true;
			bool n=false,m=false;
			if(c2[2]=='F'||c2[2]=='D'){
				n=true;
			}
			if(c4[2]=='F'||c4[2]=='D'){
				m=true;
			}
			if(n==m){
			    c=true;
			    if(abs(int(c2[2])-int(c4[2]))==1){
					d=true;
				}
		    }
		}
	}
	cout<<a<<b<<c<<d;
	return 0;	
}
