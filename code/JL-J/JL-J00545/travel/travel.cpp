#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string che1,seat1,che2,seat2;
ll hang1,hang2;
char deng1,deng2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>che1>>seat1>>che2>>seat2;
    if(che1==che2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    hang1=stoi(seat1.substr(0,2));
    hang2=stoi(seat2.substr(0,2));
    deng1=seat1[2];
    deng2=seat2[2];
    if(hang1==hang2){
        cout<<"1";
        if((deng1<'D'&&deng2<'D')||(deng1>'C'&&deng2<'C')){
            cout<<"1";
            if(deng1+1==deng2||deng1-1==deng2){
                cout<<"1";
            }else{
                cout<<"0";
            }
        }else{
            cout<<"00";
        }
    }else{
        cout<<"000";
    }
    return 0;
}
