#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cr,sr,cx,sx;
    cin>>cr>>sr>>cx>>sx;
    if(cr[0]==cx[0]&&cr[1]==cx[1]){
        if(sr[0]==sx[0]&&sr[1]==sx[1]){
            if(sr[2]>'C'&&sx[2]>'C' || sr[2]<'D'&&sx[2]<'D'){
                if(sr[2]=='A'&&sx[2]=='B'||sr[2]=='B'&&sx[2]=='C'||sr[2]=='D'&&sx[2]=='F')cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
    //freopen
    // freopen
    //ccf
    //CCF
    //yuanshen
    //Genshin

    //ba wo fang shang mi huo xing wei da shang , xiexie
