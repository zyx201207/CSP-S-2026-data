#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;string a1,b1;
    cin>>a>>a1>>b>>b1;
    if(a==b)cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    int a2=0,b2=0;
    for(int i=0;i<2;i++){
        a2=a2*10+(a1[i]-'0');
        b2=b2*10+int(b1[i]-'0');
    }
    if(a2==b2)cout<<'1';
    else {
        cout<<"000";
        return 0;
    }
    if((a1[2]<='C'&&b1[2]<='C')||(a1[2]>='D'&&b1[2]>='D'))cout<<'1';
    else {
        cout<<"00";
        return 0;
    }
    int cnt=0;
    if(a1[2]>b1[2])cnt=a1[2]-b1[2];
    else cnt=b1[2]-a1[2];
    if(cnt==1)cout<<'1';
    else cout<<'0';
    return 0;
}
