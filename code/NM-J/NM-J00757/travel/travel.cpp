#include<bits/stdc++.h>
using namespace std;
string sI,wI,sY,wY;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>sI>>wI>>sY>>wY;
    if(sI==sY){
        cout<<1;
        if(wI[0]==wY[0]&&wI[1]==wY[1]){
            cout<<1;
            if((wI[2]==('F'||'D')&&wY[2]==('F'||'D'))||(wI[2]==('A'||'B'||'C')&&wY[2]==('A'||'B'||'c'))){
                cout<<1;
                if((wI[2]==('F'||'D')&&wY[2]==('F'||'D'))||(wI[2]==('A'||'B')&&wY[2]==('A'||'B')||(wI[2]==('A'||'C')&&wY[2]==('A'||'C')||(wI[2]==('C'||'B')&&wY[2]==('C'||'B'))))){
                    cout<<1;
                }
                else{
                    cout<<"0";
                }
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
