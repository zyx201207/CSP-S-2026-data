#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    long long sum=0,cnt=0;
    cin>>a>>b>>c>>d;
    for(int i=0;i<2;i++){
        if(a[i]==c[i]){
            sum++;
        }
        if(b[i]==d[i]){
            cnt++;
        }
    }
    if(sum==2){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(cnt==2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }
    if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'){
        cout<<"00";
        return 0;
    }
    else if(b[2]<='C'&&b[2]>='A'){
        if(d[2]>='A'&&d[2]<='C'){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        if(abs(b[2]-'0'-(d[2]-'0'))==1){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    else if(b[2]>='D'&&b[2]<='F'){
        if(d[2]>='D'&&d[2]<='F'){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
        cout<<"1";
    }
    return 0;
}
