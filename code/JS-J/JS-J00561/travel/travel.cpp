#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int er=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    if(a==a1){
        cout<<1;
    }
    else{
        er=0;
        cout<<0;
    }
    if(b[0]==b1[0] and b[1]==b1[1] and er==1){
        if(er==1) cout<<1;
        else cout<<0;
    }
    else{
        cout<<0;
    }
    if(b[2]+b1[2]=='F'+'D' or b[2]+b1[2]=='C'+'A' or b[2]+b1[2]=='C'+'B' or b[2]+b1[2]=='B'+'A'){
        if(er==1 and b1[1]==b[1] and b[0]==b1[0]) cout<<1;
    else cout<<0;
    }
    else{
        cout<<0;
    }
    int x=b1[2],y=b[2];
    if(x-y==1 or x-y==-1){
        if(x+y!='C'+'D' and er==1 and b1[1]==b[1] and b[0]==b1[0])cout<<1;
        else cout<<0;
    }
    else{
        cout<<0;
    }
    return 0;
}
