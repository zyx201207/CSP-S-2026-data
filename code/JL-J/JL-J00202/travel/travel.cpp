#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string q,w,e,r;
    cin>>q>>w>>e>>r;
    if(q!=e){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        if(w[0]!=r[0]||w[1]!=r[1]){
            cout<<"000";
            //retrun 0;
        }
        else{
            cout<<1;
            char a=w[2],b=r[2];
            if(a=='A'&&b=='B')cout<<11;
            else if(a=='B'&&b=='A')cout<<11;
            else if(a=='C'&&b=='B')cout<<11;
            else if(a=='B'&&b=='C')cout<<11;
            else if(a=='A'&&b=='C')cout<<10;
            else if(a=='C'&&b=='A')cout<<10;
            else if(a=='D'&&b=='F')cout<<11;
            else if(a=='F'&&b=='D')cout<<11;
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}


