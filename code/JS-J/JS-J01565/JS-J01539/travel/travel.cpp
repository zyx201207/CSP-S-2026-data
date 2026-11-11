#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    int s1=(a1[0]-'0')*10+a1[1]-'0';
    int s2=(b1[0]-'0')*10+b1[1]-'0';
    int o1=(a2[0]-'0')*10+a2[1]-'0';
    int o2=(b2[0]-'0')*10+b2[1]-'0';
    if(s1==s2){
        cout<<1;
        if(o1==o2){
            cout<<1;
            if(a2[2]=='A'||a2[2]=='B'||a2[2]=='C'){
                if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
                    cout<<1;
                    if(abs(a2[2]-b2[2])==1){
                        cout<<1;
                    }
                    else{
                        cout<<0;
                    }
                }
                else{
                    cout<<0<<0;
                }
            }
            else{
                if(b2[2]=='A'||b2[2]=='B'||b2[2]=='C'){
                    cout<<0<<0;
                }
                else{
                    cout<<1<<1;
                }
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }

    return 0;
}
