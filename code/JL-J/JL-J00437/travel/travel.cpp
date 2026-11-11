#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        cout<<"1111";
    }
    else if(r1!=x1&&r2!=x2){
        cout<<"0111";
    }
    else{
        cout<"0000"
    }
    return 0;
}
