#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c){
    	cout<<"1";
    	if(b[1]==d[1]&&d[0]==b[0]){
    		cout<<"1";
    		if(b[2]=='A'&&d[2]=='B')cout<<"11";
	        if(b[2]=='A'&&d[2]=='C')cout<<"10";
           	if(b[2]=='A'&&d[2]=='D')cout<<"00";
	        if(b[2]=='A'&&d[2]=='F')cout<<"00";
	        if(b[2]=='B'&&d[2]=='A')cout<<"11";
	        if(b[2]=='B'&&d[2]=='C')cout<<"11";
	        if(b[2]=='B'&&d[2]=='D')cout<<"00";
	        if(b[2]=='B'&&d[2]=='F')cout<<"00";
        	if(b[2]=='C'&&d[2]=='A')cout<<"10";
        	if(b[2]=='C'&&d[2]=='B')cout<<"11";
        	if(b[2]=='C'&&d[2]=='D')cout<<"00";
        	if(b[2]=='C'&&d[2]=='F')cout<<"00";
        	if(b[2]=='D'&&d[2]=='A')cout<<"00";
        	if(b[2]=='D'&&d[2]=='B')cout<<"00";
        	if(b[2]=='D'&&d[2]=='C')cout<<"00";
        	if(b[2]=='D'&&d[2]=='F')cout<<"11";
        	if(b[2]=='F'&&d[2]=='A')cout<<"00";
        	if(b[2]=='F'&&d[2]=='B')cout<<"00";
        	if(b[2]=='F'&&d[2]=='C')cout<<"00";
        	if(b[2]=='F'&&d[2]=='D')cout<<"11";
		}
	    else cout<<"000";
	}
	else cout<<"0000";
	
	
	return 0;
}//Trick||Treat!
