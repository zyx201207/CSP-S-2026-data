#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    char d1=b1[2],d2=b2[2];
    if(a1[0]==a2[0]&&a1[1]==a2[1]){
        cout<<1;
        if(b1[0]==b2[0]&&b1[1]==b2[1]){
            cout<<"1";
            if(d1<'D'&&d2<'D'||d1>'C'&&d2>'C'){
                cout<<"1";
                if(d1-d2==1&&d1!='D'||d1-d2==-1&&d1!='C'){
                    cout<<"1"<<endl;
                }
                else{
                    cout<<"0"<<endl;
                }
            }
            else{
                cout<<"00"<<endl;
            }
        }
        else{
            cout<<"000"<<endl;
        }
    }
    else{
        cout<<"0000"<<endl;
    }
}
