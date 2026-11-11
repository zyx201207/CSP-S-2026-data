#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1!=b1){
        cout<<"0000";
    }
    else {
        cout<<"1";
        string s1,s2;
        char m=a2[2],n=b2[2];
        s1+=a2[0]+a2[1];
        s2+=b2[0]+b2[1];
        if(s1!=s2){
            cout<<"000";
        }
        else{
            cout<<"1";
            if(m<='C'&&n<='C' || m>'C'&&n>'C'){
                cout<<"1";
                if((m+1==n||m-1==n)&&(m!='C'&&n!='D')){
                    cout<<"1";
                }
                else {
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
    }
    return 0;
}
