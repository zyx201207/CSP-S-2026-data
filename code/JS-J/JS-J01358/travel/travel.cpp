#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a=0;
bool b=0;
bool c=0;
bool d=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
        b=1;
			if(s1[2]>='A'&&s1[2]<='B'){
				if(s1[2]+1==s2[2]){
					c=1;
				}
			}
			else if(s2[2]>='A'&&s2[2]<='B'){
				if(s2[2]+1==s1[2]){
					c=1;
				}
			}
			if(s1[2]=='D'){
				if(s1[2]+2==s2[2]){
					c=1;
				}
			}
			else if(s2[2]=='D'){
				if(s2[2]+2==s1[2]){
					c=1;
				}	
			}
		}
	}
		if(a==1&&b==1&&c==1){
			cout<<a<<b<<c<<d;
		}
		else{
			d=0;
			cout<<a<<b<<c<<d;
		}
    return 0;
}
