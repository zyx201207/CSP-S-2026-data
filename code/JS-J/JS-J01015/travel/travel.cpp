#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1 , st , c2 , str;
    cin>>c1>>st>>c2>>str;

    if(c1 == c2){
            cout<<"1";
        if(st[0] == str[0] && st[1] == str[1]){
            cout<<"1";
            if('A' <= st[2] && st[2] <= 'C' && 'A' <= str[2] && str[2] <= 'C' && str[2] != st[2]){
                cout<<"1";
                if((st[2] == 'D' && str[2] == 'C') || (st[2] == 'C' && str[2] == 'D')){
                    cout<<"0";
                }else{
                    if((st[2] - 1 == str[2]) || (st[2] + 1 == str[2])){
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
