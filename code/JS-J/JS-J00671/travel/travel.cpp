#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a[0]!=c[0]||a[1]!=c[1]){
        cout<<"0000";
        return 0;
    }
    ans[0]='1';
    if(b[0]==d[0]&&b[1]==d[1]){
        ans[1]='1';
    }else{
        ans[1]=ans[2]=ans[3]='0';
        cout<<ans;
        return 0;
    }
    if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D'){
        ans[2]='1';
    }else{
        ans[2]=ans[3]='0';
        cout<<ans;
        return 0;
    }
    int x=b[2]-'A';
    int y=d[2]-'A';
    if(abs(x-y)==1){
        ans[3]='1';
    }else{
        ans[3]='0';
    }
    cout<<ans;
    return 0;
}
