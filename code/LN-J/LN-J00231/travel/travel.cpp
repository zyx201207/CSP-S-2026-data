#include<bits/stdc++.h>
using namespace std;
string a,b;
int sum1,sum2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sum1>>a>>sum2>>b;
    if(sum1==sum2){
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<"1";
            if(a[2]<='C'&&b[2]<='C'||a[2]>'C'&&a[2]>'C'){
                cout<<"1";
                if(a[2]+1==b[2]||b[2]+1==a[2]){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
