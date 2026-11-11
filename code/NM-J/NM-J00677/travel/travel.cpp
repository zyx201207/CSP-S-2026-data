#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int last=1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<'1';
    else{
        cout<<'0';
        last=0;
    }
    int f;
    if(last==0)f=0;
    else f=1;
    for(int i=0;i<b.size()-1;i++){
        if(b[i]!=d[i]){
            f=0;
            break;
        }
    }
    cout<<f;
    last=f;
    int ff=1;
    if(last==0){
        cout<<'0';
        ff=0;
    }
    if(b[b.size()-1]>='D'&&d[d.size()-1]<='C')ff=0;
    else if(b[b.size()-1]<='C'&&d[d.size()-1]>='D')ff=0;
    if(ff!=0)cout<<ff;
    last=ff;
    if(last==0){
        cout<<'0';
        return 0;
    }
    else if(b[b.size()-1]=='A'&&d[d.size()-1]=='B')cout<<'1';
    else if(b[b.size()-1]=='B'&&d[d.size()-1]=='C')cout<<'1';
    else if(b[b.size()-1]=='D'&&d[d.size()-1]=='F')cout<<'1';
    else if(b[b.size()-1]=='C'&&d[d.size()-1]=='B')cout<<'1';
    else if(b[b.size()-1]=='B'&&d[d.size()-1]=='A')cout<<'1';
    else if(b[b.size()-1]=='F'&&d[d.size()-1]=='D')cout<<'1';
    else cout<<'0';
    return 0;
}
