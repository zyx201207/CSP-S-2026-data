#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.on","w",stdout);
    int c1,s1,c2,s2;
    char n,m;
    cin>>c1>>s1>>n>>c2>>s2>>m;
    if(c1==c2&&c1!=01&&c1!=16) cout<<1;
        else{
           	cout<<"0000";
			return 0;	
		} 

    if(s1==s2) cout<<1;
        else{
        	cout<<"000";
        	return 0;
		} 
    if(n<='C'&&m<='C') cout<<1;
    else if(n=='D'&&m=='F') {
    	cout<<"11";
    	return 0;
	}
        else if(m=='D'&&n=='F') {
		    cout<<"11";
		    return 0;
		}
            else{
            	cout<<"00";
            	return 0;
			}
    if(n+1==m&&m<=67) cout<<1;
    else if(m+1==n&&n<=67) cout<<1;
    	else cout<<0;
	return 0;
} 
