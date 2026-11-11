#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string x1,y1;
string x2,y2;
cin>>x1>>x2>>y1>>y2;
if(x1==y1){
    cout<<1;
    if(x2[1]==y2[1]&&x2[0]==y2[0]){
        cout<<1;
        if(x2[3]-'A'>=3&&y2[3]-'A'>=3){
            cout<<1;
            if(x2[3]-y2[3]==1){
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        else if(x2[3]-'A'<=2&&y2[3]-'A'<=2){
            cout<<1;
            if(x2[3]-y2[3]==1){
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
        cout<<0<<0<<0;
    }
}
else{
    cout<<0<<0<<0<<0;
}
return 0;
}
