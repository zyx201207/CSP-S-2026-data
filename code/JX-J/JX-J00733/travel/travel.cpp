#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a1,b1,a2,b2;
    char a3,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<b1<<" "<<b2<<" "<<b3;
    if(a1==b1){
        cout<<"1";
    }
    else{
        cout<<"0000";
        return 0;
    }

    if(a2==b2){
        cout<<"1";
    }
    else{
        cout<<"000";
        return 0;
    }

    if((a3=='A' or a3=='B' or a3=='C') and (b3=='A' or b3=='B' or b3=='C')){
        cout<<"1";
    }
    else if((a3=='D' or a3=='E') and (a3=='D' or a3=='E')){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }

    if(a3=='A' and b3=='B'){
        cout<<"1";
    }
    else if(a3=='B' and b3=='A'){
        cout<<"1";
    }
    else if(a3=='B' and b3=='c'){
        cout<<"1";
    }
    else if(a3=='c' and b3=='B'){
        cout<<"1";
    }
    else if(a3=='D' and b3=='E'){
        cout<<"1";
    }
    else if(a3=='E' and b3=='D'){
        cout<<"1";
    }
    else{
        cout<<"0";
        return 0;
    }

    return 0;
}
