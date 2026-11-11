#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c!=cc){
        cout<<"0000";
    }
    else{
        cout<<1;
        if(s[0]!=ss[0]||s[1]!=ss[1]){
            cout<<"000";
        }
        else{
            cout<<1;
            if(s[2]>='A'&&ss[2]<='C'){
                cout<<1;
                if(s[2]=='A'&&ss[2]=='B')cout<<1;
                else if(s[2]=='B'&&ss[2]=='C')cout<<1;
                else cout<<0;
            }
            else if(s[2]=='D'&&ss[2]=='F')cout<<"11";
            else cout<<"00";
        }
    }
    return 0;
}
