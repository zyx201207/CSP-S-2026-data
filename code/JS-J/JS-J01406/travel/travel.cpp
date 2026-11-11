#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool f1,f2,f3,f4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a1>>a2>>b1>>b2;
    f1=false;f2=false;f3=false;f4=false;
    if(a1==b1){
        f1=true;
    }
    else{
        f1=false;
    }


    if(a2[0]==b2[0] and a2[1]==b2[1]){
        f2=true;
    }
    else{
        f2=false;
    }


    if(a2[2]=='A' or a2[2]=='B' or a2[2]=='C'){
        if(b2[2]=='A' or b2[2]=='B' or b2[2]=='C'){
            f3=true;
        }
    }
    else if(a2[2]=='D' or a2[2]=='F'){
        if(b2[2]=='D' or b2[2]=='F'){
            f3=true;
        }
    }


    if(a2[2]=='A'){
        if(b2[2]=='B'){
            f4=true;
        }
    }
    else if(a2[2]=='B'){
        if(b2[2]=='A' or b2[2]=='C'){
            f4=true;
        }
    }
    else if(a2[2]=='C'){
        if(b2[2]=='B'){
            f4=true;
        }
    }
    else if(a2[2]=='D'){
        if(b2[2]=='F'){
            f4=true;
        }
    }
    else if(a2[2]=='F'){
        if(b2[2]=='D'){
            f4=true;
        }
    }
    if(f1==false){
        f2=false;f3=false;f4=false;
    }
    if(f2==false){
        f3=false;f4=false;
    }
    if(f3==false){
        f4=false;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
