#include<bits/stdc++.h>
using namespace std;
int g[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int p=0;
    string a;
    string b;
    string c;
    string d;
    cin>>a>>c>>b>>d;
    if(a[0]==b[0]&&a[1]==b[1]){
        g[1]=1;
    }else{
        for(int i=1;i<=4;i++){
            cout<<0;
        }
        return 0;
    }
    if(c[0]==d[0]&&c[1]==d[1]){
        g[2]=1;
    }else{
        cout<<1<<0<<0<<0;
        return 0;
    }
    if(c[2]=='A'||c[2]=='B'||c[2]=='C'&&d[2]=='A'||d[2]=='B'||d[2]=='c'){
        g[3]=1;
    }else{
        if(c[2]=='D'||c[2]=='F'&&d[2]=='D'||d[2]=='F'){
            g[3]=1;
        }else{
            cout<<1<<1<<0<<0;
            return 0;
        }
    }
    if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&d[2]=='A'||c[2]=='B'&&d[2]=='C'||c[2]=='C'&&d[2]=='B'||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D'){
        g[4]=1;
    }else{
        cout<<1<<1<<1<<0;
        return 0;
    }
    for(int i=1;i<=4;i++){
        cout<<g[i];
    }
    return 0;
}
