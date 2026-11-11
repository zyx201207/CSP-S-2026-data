#include<bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
bool l=false,r=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    int rs_num,xs_num;
    rs_num=(rs[0]-'0')*10+(rs[1]-'0');
    xs_num=(xs[0]-'0')*10+(xs[1]-'0');
    l=int(rs[2]-'A')<3 && int(xs[2]-'A')<3;
    r=int(rs[2]-'A')>2 && int(xs[2]-'A')>2;

    if(rc==xc){
        cout<<"1";
        if(rs_num==xs_num){
            cout<<"1";
            if(l||r){
                cout<<"1";
                if(l){
                    if(abs(int(rs[2]-'A')-int(xs[2]-'A'))==1){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    if(abs(int(rs[2]-'A')-int(xs[2]-'A'))==2){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
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
