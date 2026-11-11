#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long cnt=0;
    cin>>c1>>c2>>s1>>s2;
    if(c1[0]==s1[0]&&c1[1]==s1[1]){
    cout<<1;
    }else{
    cout<<0;
    }
    if(c2[0]==s2[0]&&c2[1]==s2[1]){
    cout<<1;
    }else{
    cout<<0;
    }

    cout<<0;
    cout<<0;
    return 0;
}
