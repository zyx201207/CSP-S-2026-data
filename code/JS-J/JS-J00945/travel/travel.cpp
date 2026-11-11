#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            if(a2[2]=='A'){
                if(b2[2]=='B'){
                    cout<<"1111";
                }else if(b2[2]=='C'){
                    cout<<"1110";
                }else{
                    cout<<"1100";
                }
            }else if(a2[2]=='B'){
                if(b2[2]=='A'){
                    cout<<"1111";
                }else if(b2[2]=='C'){
                    cout<<"1111";
                }else{
                    cout<<"1100";
                }

            }else if(a2[2]=='C'){
                if(b2[2]=='B'){
                    cout<<"1111";
                }else if(b2[2]=='A'){
                    cout<<"1110";
                }else{
                    cout<<"1100";
                }
            }else if(a2[2]=='D'){
                if(b2[2]=='F'){
                    cout<<"1111";
                }else{
                    cout<<"1100";
                }
            }else if(a2[2]=='F'){
                if(b2[2]=='D'){
                    cout<<"1111";
                }else{
                    cout<<"1100";
                }
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
