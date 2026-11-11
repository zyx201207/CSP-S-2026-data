#include<bits/stdc++.h>
using namespace std;
int s[5]={1,1,1,0,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b){
        if(a1[0]==b1[0]&&a1[1]==b1[1]){
            if(s[a1[2]-65]==s[b1[2]-65]){
                if(abs(int(a1[2]-b1[2]))==1){
                    cout<<1111;
                }
                else{
                    cout<<1110;
                }
            }
            else{
                cout<<1100;
            }
        }
        else{
            cout<<1000;
        }
    }
    else{
        cout<<"0000";
    }

    return 0;
}
