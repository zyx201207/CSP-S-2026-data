#include<bits/stdc++.h>
using namespace std;
string x,y,a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(x[0]==y[0] &&x[1]==y[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(x[2]=='A'){
        if(y[2]=='B' || y[2]=='C'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(x[2]=='B'){
        if(y[2]=='A' || y[2]=='C'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(x[2]=='C'){
        if(y[2]=='B' || y[2]=='A'){
            cout<<1;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(x[2]=='D'){
        if(y[2]=='F'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(x[2]=='F'){
        if(y[2]=='D'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    if(x[2]=='C' && y[2]=='B'){
        cout<<1;
    }
    else if(x[2]=='B' && (y[2]=='C' ||y[2]=='A')){
        cout<<1;
    }
    else if(x[2]=='A' && y[2]=='B'){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
