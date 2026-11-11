#include<bits/stdc++.h>
#define ll long long
#define int long long 
using namespace std;
string s,ss,x,xx;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s>>xx>>ss;
	if(x==xx){
		cout<<1;
		if(s[0]==ss[0] && s[1]==ss[1]){
	    	cout<<1;
    		if(((s[2]=='A' || s[2]=='B' || s[2]=='C') && (ss[2]=='A' || ss[2]=='B' || ss[2]=='C')) || ((s[2]=='D' || s[2]=='F') && (ss[2]=='D' || ss[2]=='F'))) {
    			cout<<1;
    			if(s[2]-1==ss[2] || s[2]==ss[2]-1){
    				cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			} 
    	}else{
	    	cout<<0<<0<<0;
    	}
	}else{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
}
