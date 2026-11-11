#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w", stdout);
    string a,s,d,f;
    cin>>a>>s>>d>>f;
    int num=0;
    if(a==d){
        cout<<1;
                if(s[0]==f[0]&&s[1]==f[1]){
            cout<<1;
            if(s[2]=='A'||s[2]=='B'||s[2]=='C'){
                if(f[2]=='A'||f[2]=='B'||f[2]=='C'){
                    cout<<1;
                    if(f[2]=='A'&&s[2]=='B'){
                        cout<<1;
                    }else if(f[2]=='B'&&s[2]=='C'){
                        cout<<1;
                    }else if(f[2]=='B'&&s[2]=='A'){
                        cout<<1;
                    }else if(f[2]=='C'&&s[2]=='B'){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }else{
                if(s[2]=='D'||s[2]=='F'){
                    if(f[2]=='D'||f[2]=='F'){
                        cout<<"11";
                    }else{
                        cout<<"00";
                    }
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
