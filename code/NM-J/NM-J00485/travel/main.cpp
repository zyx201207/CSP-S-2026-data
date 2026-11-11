#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<"1";
        if(c2[0]==s2[0]&&c2[1]==s2[1]){
            cout<<"1";
            char a=c2[2] ;
            char b=s2[2] ;
            if(a<='C'&&b<='C'||a>='D'&&b>='D'){
                cout<<"1";
                if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='F'&&b=='D')||(a=='D'&&b=='F')||(a=='B'&&b=='A')||(a=='C'&&b=='B')){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
