#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx;
int main(){
 	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cr>>sr>>cx>>sx;
    if(cr==cx){
        cout<<1;
        int r=(sr[0]-'0')*10+(sr[1]-'0');
        int x=(sx[0]-'0')*10+(sx[1]-'0');
        if(x==r){
            cout<<1;
            sx=sx[2];
            sr=sr[2];
            if((sr<="C" and sx<="C") or (sr>="D" and sx>="D")){
                cout<<1;
                r=sr[2]-'A';
                x=sx[2]-'A';
                if((x+1==r and sx!="C") or (x==r+1 and cr!="D")){
                    cout<<1;
                }else cout<<0;
            }else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}
