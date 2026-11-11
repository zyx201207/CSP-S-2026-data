#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a[3],b[3],c[4],d[4];
    for(int i=0;i<=1;i++){
        cin>>a[i];
    }
    for(int i=0;i<=2;i++){
        cin>>c[i];
    }
    for(int i=0;i<=1;i++){
        cin>>b[i];
    }
    for(int i=0;i<=2;i++){
        cin>>d[i];
    }
    if(a[0]==b[0]&&a[1]==b[1]){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==d[0]&&c[1]==d[1]){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(c[2]=='A'){
        if(d[2]=='B'||d[2]=='C'){
            cout<<"1";
        }
        else{
        cout<<"00";
        return 0;
        }
    }
    else if(c[2]=='B'){
        if(d[2]=='A'||d[2]=='C'){
            cout<<"1";
        }
        else{
        cout<<"00";
        return 0;
        }
    }
    else if(c[2]=='C'){
        if(d[2]=='B'||d[2]=='A'){
            cout<<"1";
        }
        else{
        cout<<"00";
        return 0;
        }
    }
    else if(c[2]=='D'){
        if(d[2]=='F'){
            cout<<"1";
        }
        else{
        cout<<"00";
        return 0;
        }
    }
    else if(c[2]=='F'){
        if(d[2]=='D'){
            cout<<"1";
        }
        else{
        cout<<"00";
        return 0;
        }
    }
    if(c[2]=='A'){
        if(d[2]=='B'){
            cout<<"1";
        }
        else{
            cout<<"0";
            return 0;
        }
    }
    else if(c[2]=='B'){
        if(d[2]=='C'){
            cout<<"1";
        }
        else{
        cout<<"0";
        return 0;
        }
    }
    else if(c[2]=='C'){
        if(d[2]=='B'){
            cout<<"1";
        }
        else{
        cout<<"0";
        return 0;
        }
    }
    else if(c[2]=='D'){
        if(d[2]=='F'){
            cout<<"1";
        }
        else{
        cout<<"0";
        return 0;
        }
    }
    else if(c[2]=='F'){
        if(d[2]=='D'){
            cout<<"1";
        }
        else{
        cout<<"0";
        return 0;
        }
    }
    return 0;
}
