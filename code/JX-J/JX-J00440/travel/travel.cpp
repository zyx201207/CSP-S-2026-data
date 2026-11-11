#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cx,sx,cy,sy;
    int flag=1;
    cin>>cx>>sx>>cy>>sy;
    if(cx!=cy){
        cout<<"000";
        flag=0;
    }else{
        cout<<'1';
        if(sx[0]==sy[0]&&sx[1]==sy[1]){
            cout<<"1";
            if(sx[2]=='A'){
                if(sy[2]=='A'||sy[2]=='B'||sy[2]=='C'){
                    cout<<"1";
                }else{
                    cout<<'0';
                    flag=0;
                }
            }else if(sx[2]=='B'){
                if(sy[2]=='A'||sy[2]=='B'||sy[2]=='C'){
                    cout<<"1";
                }else{
                    cout<<'0';
                    flag=0;
                }
            }else if(sx[2]=='C'){
                if(sy[2]=='A'||sy[2]=='B'||sy[2]=='C'){
                    cout<<"1";
                }else{
                    cout<<'0';
                    flag=0;
                }
            }else{
                if(sy[2]=='D'||sy[2]=='F'){
                    cout<<'1';
                }else{
                    cout<<'0';
                    flag=0;
                }
            }
        }else{
            cout<<"00";
            flag=0;
        }
    }
    if(flag==1&&(sx[2]==sy[2]+1||sx[2]==sy[2]-1)){
        cout<<'1';
    }else{
        cout<<'0';
    }
    return 0;
}
