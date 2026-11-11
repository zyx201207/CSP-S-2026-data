#include <bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if (cr==cx){
	    cout<<1;
	    bool flag=0;
		if (sr[0]==sx[0] && sr[1]==sx[1]){
			cout<<1;
			if (sr[2]=='A' || sr[2]=='B' || sr[2]=='C'){
		        if (sx[2]=='A' || sx[2]=='B' || sx[2]=='C') cout<<1;
		        else cout<<0;
	        }if (sr[2]=='D' || sr[2]=='F'){
		        if (sx[2]=='D' || sx[2]=='F') cout<<1;
		        else cout<<0;
	        }
			if (sr[2]=='A' && sx[2]=='B') cout<<1,flag=1;
	        if (sr[2]=='B' && sx[2]=='C') cout<<1,flag=1;
	        if (sr[2]=='D' && sx[2]=='F') cout<<1,flag=1;
	        if (flag==0) cout<<0;
		}
	    else cout<<0<<0<<0;
	} 
	else cout<<0<<0<<0<<0;
	return 0;
}