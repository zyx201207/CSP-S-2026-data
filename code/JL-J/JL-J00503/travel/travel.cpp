#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b2,a2,b1,a,b;
    cin>>a1;
    cin>>a2;
    cin>>b1;
    cin>>b2;
    a=a1+a2;
    b=b1+b2;
    if(a1==b1){
        cout<<1;
        if((a2[0]==b2[0])&&(a2[1]==b2[1])){
            cout<<1;
            if(a2[2]+b2[2]==138){
                cout<<"11";
            }
            else if(a2[2]+b2[2]==133){
                        cout<<"11";
                    }
            else if(a2[2]+b2[2]==131){
                        cout<<"11";
                    }
            else if(a2[2]+b2[2]==132){
                        cout<<"10";
                    }
            else{
                cout<<"00";
            }

        }else{
            cout<<"000";
        }

    }
    else{
        cout<<"0000";
    }
return 0;
}
