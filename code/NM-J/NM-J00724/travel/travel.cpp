#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,a1,b1,b,c;
    cin>>a>>a1>>b>>b1;
    if(a==b){
        if(a1[0]==b1[0]&&a1[1]==b1[1]){
            if((a1[2]=='A'||a1[2]=='B'||a1[2]=='C')&&(b1[2]=='A'||b1[2]=='B'||b1[2]=='C')){
                if(a1[2]=='A'&&b1[2]!='C'){
                    cout<<"1111"<<endl;
                }
                else if(a1[2]=='C'&&b1[2]!='A'){
                    cout<<"1111"<<endl;
                }
                else{
                    cout<<"1110"<<endl;
                }
            }
            else if((a1[2]=='D'||a1[2]=='F')&&(b1[2]=='D'||b1[2]=='F')){
                cout<<"1111"<<endl;
            }
            else{
                cout<<"1100"<<endl;
            }
        }
        else{
            cout<<"1000"<<endl;
        }
    }
    else{
        cout<<"0000"<<endl;
    }
    return 0;
}
