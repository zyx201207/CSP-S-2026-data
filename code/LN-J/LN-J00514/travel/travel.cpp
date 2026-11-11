#include<bits/stdc++.h>
using namespace std;
string a_box,a_pos,b_box,b_pos;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a_box>>a_pos>>b_box>>b_pos;
    if(a_box[0]==b_box[0]&&a_box[1]==b_box[1]){
        cout<<"1";
        if(a_pos[0]==b_pos[0]&&a_pos[1]==b_pos[1]){
            cout<<"1";
            if((a_pos[2]=='A'&&b_pos[2]=='B')||(a_pos[2]=='B'&&b_pos[2]=='A')||(a_pos[2]=='A'&&b_pos[2]=='C')||(a_pos[2]=='C'&&b_pos[2]=='A')||(a_pos[2]=='B'&&b_pos[2]=='C')||(a_pos[2]=='C'&&b_pos[2]=='B')||(a_pos[2]=='D'&&b_pos[2]=='E')||(a_pos[2]=='E'&&b_pos[2]=='D')){
                cout<<"1";
                if((a_pos[2]=='A'&&b_pos[2]=='B')||(a_pos[2]=='B'&&b_pos[2]=='A')||(a_pos[2]=='B'&&b_pos[2]=='C')||(a_pos[2]=='C'&&b_pos[2]=='B')||(a_pos[2]=='D'&&b_pos[2]=='E')||(a_pos[2]=='E'&&b_pos[2]=='D')){
                    cout<<"1";
                    return 0;
                }else{
                    cout<<"0";
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
