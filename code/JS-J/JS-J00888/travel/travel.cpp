#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int r,x;
string sr,sx;
char a,b;
int rp,xp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>r>>sr>>x>>sx;
    if(r!=x){
        cout<<"0000";
    }else{
        cout<<"1";
        rp=0;
        rp=(sr[0]-'0')*10+(sr[1]-'0');
        xp=0;
        xp=(sx[0]-'0')*10+(sx[1]-'0');
        if(rp!=xp){
            cout<<"000";
        }else{
            cout<<"1";
            a=sr[sr.size()-1];
            b=sx[sx.size()-1];
            if(a<'D'&&b<'D'||a>='D'&&b>='D'){
                cout<<"1";
                if(abs(a-b)==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }
    }
    return 0;
}
/*
02 01C 02 01A
*/
