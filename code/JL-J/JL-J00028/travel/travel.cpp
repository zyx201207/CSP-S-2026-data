#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        cout<<'1';
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<'1';
            if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')){
                cout<<'1';
                if(abs(a2[2]-b2[2])==1)cout<<'1'<<"\n";
                else cout<<'0'<<"\n";
            }
            else cout<<"00"<<"\n";
        }
        else cout<<"000"<<"\n";
    }
    else cout<<"0000"<<"\n";
return 0;
}
