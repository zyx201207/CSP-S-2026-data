#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[1]-'0'+s1[2]-'0'==s2[1]-'0'+s2[2]-'0' || s1[1]-'0'+s1[2]-'0'==s2[1]-'0'+s2[2]-'0'){
            cout<<1;
            if((s1[3]-'0'<=12) && (s2[3]-'0'<=12) || (s1[3]-'0'>=13) && (s2[3]-'0'>=13)){
                cout<<1;
				if(s1[3]-'0'==s2[3]-'0'+1 || s1[3]-'0'==s2[3]-'0'-1)
                {
	    			cout<<1;
				}
				else{
	    			cout<<0;
				}            
            }
            else{
                cout<<00;
            }
        }
        else{
            cout<<000;
        }             
    }
    else{
        cout<<0000;
    }
    return 0;
}
