#include<bits/stdc++.h>
using namespace std;
long long a,b;
string x,y;
long long m,n;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>x>>b>>y;
    m=(x[0]-'0')*10+(x[1]-'0');
    n=(y[0]-'0')*10+(y[1]-'0');
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(m==n){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(x[2]-'A'<=2&&y[2]-'A'<=2){
        cout<<1;
        if(x[2]-'A'+1==y[2]-'A'||x[2]-'A'-1==y[2]-'A'){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    else{
        if((x[2]=='D'||x[2]=='F')&&(y[2]=='F'||y[2]=='D')){
            cout<<11;
        }
        else{
            cout<<"00";
        }
        return 0;
    }
    return 0;
}
