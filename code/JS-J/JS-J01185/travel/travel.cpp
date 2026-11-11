#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool aaa=false,bbb=false,ccc=false;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        bbb=true;
    }else{
        cout<<0;
    }
    if((b[0]==d[0]&&b[1]==d[1])&&bbb){
        cout<<1;
        ccc=true;
    }else{
        cout<<0;
    }
    if(((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&ccc){
        cout<<1;
        aaa=true;
    }else{
        cout<<0;
    }
    if(((int(b[2]+1)==int(d[2]))||(int(b[2])==int(d[2]+1)))&&aaa){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
