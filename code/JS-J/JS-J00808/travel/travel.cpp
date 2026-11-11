#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(s1[1]==s2[1]&&s1[0]==s2[0]){
            cout<<1;
            char a,b;
            a=s1[2];
            b=s2[2];
            if(a=='F'&&b=='D'){
                cout<<"11";
                return 0;
            }
            if(a=='D'&&b=='F'){
                cout<<"11";
                return 0;
            }
            if(a<='C'&&b<='C'&&a>='A'&&b>='A'){
                cout<<1;
                if(a=='A'){
                    if(b=='B'){
                        cout<<1;
                        return 0;
                    }
                    if(b=='C'){
                        cout<<0;
                        return 0;
                    }
                }
                if(a=='C'){
                    if(b=='B'){
                        cout<<1;
                        return 0;
                    }
                    if(b=='A'){
                        cout<<0;
                        return 0;
                    }
                }
                if(a=='B'){
                    if(b=='C'){
                        cout<<1;
                        return 0;
                    }
                    if(b=='A'){
                        cout<<1;
                        return 0;
                    }
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
    else {
        cout<<"0000";
        return 0;
    }
    return 0;
}
