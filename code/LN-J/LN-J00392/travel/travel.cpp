#include<bits/stdc++.h>
using namespace std;
int c_1,c_2;
string s_1,s_2;
bool tx(int x,int y){
    return x==y;
}
bool tp(string x,string y){
    return x[0] == y[0] && x[1] == y[1];
}
bool tc(string x,string y){
    if((x[2] == 'A' && y[2] == 'B') || (x[2] == 'A' && y[2] == 'C') || (x[2] == 'B' && y[2] == 'A') || (x[2] == 'B' && y[2] == 'C') ||(x[2] == 'C' && y[2] == 'B')||(x[2] == 'C' && y[2] == 'A')){
        return 1;
    }else if((x[2] == 'D' && y[2] == 'F')||(x[2] == 'F' && y[2] == 'D')){
        return 1;
    }else{
        return 0;
    }
}
bool xl(string x,string y){
    if((x[2] == 'A' && y[2] == 'B')||(x[2] == 'B' && y[2] == 'A')||(x[2] == 'B' && y[2] == 'C')||(x[2] == 'C' && y[2] == 'B')){
        return 1;
    }else if((x[2] == 'D' && y[2] == 'F')||(x[2] == 'F' && y[2] == 'D')){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c_1>>s_1>>c_2>>s_2;
    if(tx(c_1,c_2)){
        cout<<"1";
        if(tp(s_1,s_2)){
            cout<<"1";
            if(tc(s_1,s_2)){
                cout<<"1";
                if(xl(s_1,s_2)){
                    cout<<"1";
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
