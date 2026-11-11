#include<bits/stdc++.h>
using namespace std;
string e="ABC";
string f="DF";
bool zq(string z,string q){
    for(int i=0;i<3;i++){
        if(z[2]==e[i]){
            if(q[2]==e[1] || q[2]==e[0] || q[2]==e[2]){
                return true;
            }
        }
    }
    for(int i=0;i<2;i++){
        if(z[2]==f[i]){
            if(q[2]==f[0] || q[2]==f[1]){
                return true;
            }
        }
    }
    return false;
}
bool gh(string g,string h){
    for(int i=0;i<3;i++){
        if(g[2]==e[i]){
            if(i==0){
                if(h[2]==e[1]){
                    return true;
                }
            }
            if(i==1){
                if(h[2]==e[0] || h[2]==e[2]){
                    return true;
                }
            }
            if(i==2){
                if(h[2]==e[1]){
                    return true;
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        if(g[2]==f[i]){
            if(i==0){
                if(h[2]==f[1]){
                    return true;
                }
            }
            if(i==1){
                if(h[2]==f[0]){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(b[0]==d[0] && b[1]==d[1]){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    if(zq(b,d)==true){
        cout<<1;
    }
    else{
        cout<<0;
        cout<<0;
        return 0;
    }
    if(gh(b,d)==true){
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}
