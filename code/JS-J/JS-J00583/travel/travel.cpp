#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string r1,r2;
    cin>>c1>>r1;
    cin>>c2>>r2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    if(r1[0]!=r2[0]||r1[1]!=r2[1]){
        cout<<"1000";
        return 0;
    }
    if(r1[2]>='A'&&r1[2]<='C'&&(r2[2]=='D'||r2[2]=='E')){
        cout<<"1100";
        return 0;
    }
    if(r2[2]>='A'&&r2[2]<='C'&&(r1[2]=='D'||r1[2]=='E')){
        cout<<"1100";
        return 0;
    }
    if(abs(int(r1[2])-int(r2[2]))!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
