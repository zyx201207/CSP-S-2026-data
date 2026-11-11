#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	    cout<<1;
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
	    	cout<<1;
		    if(s1[2]+s2[2]<=133||s1[2]+s2[2]==137){
		    	cout<<1;
			    if(s1[2]+s2[2]==137){
			    	cout<<1;
				}
			    else if(s1[2]==65&&s2[2]==66)cout<<1;
			    else if(s1[2]==66&&s2[2]==67)cout<<1;
			    else cout<<0;
			}
		    else cout<<0<<0;
		}
	    else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
