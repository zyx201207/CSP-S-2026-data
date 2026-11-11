#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int a,b;

int main(){
    freopen("travel.in","w",stdin);
    freopen("travel.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else cout<<"1";

    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    //cout<<s1[1]<<" and "<<s1[2]<<"\n";
    if(a!=b){
        cout<<"000";
        return 0;
    }
    else cout<<"1";

    a=s1[2];
    b=s2[2];
    if(( 'C'-s1[2] >=0&& 'C'-s2[2] >=0)||( s1[2]-'D' >=0&& s2[2]-'D' >=0)){
        cout<<"1";
    }
    else{
        cout<<"00";
        return 0;
    }

    if(abs(a-b)==1){
        cout<<"1";
    }
    else cout<<"0";



    return 0;
}
