#include<bits/stdc++.h>
using namespace std;
string r1="",r2="",x1="",x2="";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1!=x1){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<1;
        if((r2[0]!=x2[0]) ||(r2[1]!=x2[1])){
            cout<<"000";
            return 0;
        }
        else{
            cout<<1;
            int r=r2[2]-'A',x=x2[2]-'A';
            if(r>x) swap(r,x);
            if(x<3){
                cout<<'1';
                if(x-r==1){
                    cout<<'1';
                    return 0;
                }
                else{
                    cout<<'0';
                    return 0;
                }
            }
            else if(r>2){
                cout<<"11";
                return 0;
            }
            else{
                cout<<"00";
                return 0;
            }
        }
    }
    return 0;
}
