#include <iostream>
#include <cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n1,n2;
    string a,b;
    cin>>n1>>a>>n2>>b;
    if(n1==n2){
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<"1";
            if(a[2]<='C'&&b[2]<='C'){
                cout<<"1";
                if(abs(a[2]-b[2])==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if(a[2]>='D'&&b[2]>='D'){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
