#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1[0]==s3[0]&&s1[1]==s3[1]) cout<<1;
        else{
			cout<<0<<0<<0<<0;
			return 0;
		}
    if(s2[1]==s4[1]&&s2[0]==s2[0]) cout<<1;
        else{
			cout<<0<<0<<0;
			return 0;
		}
    a=(s2[2]-'A')+1;
    b=(s4[2]-'A')+1;
    if((a<4&&b<4)||(a<7&&a>=4&&b>=4&&b<7)) cout<<1;
        else{
		    cout<<0<<0;
		    return 0;	
		}
	if(a+1==b||b+1==a||(a==4&&b==6)||(a==6&&b==4)) cout<<1;
	    else cout<<0;
    return 0;
}
