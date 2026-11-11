#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool ck(char x,char y){
    if(x>y)swap(x,y);
    if(x=='A'&&y=='B')return true;
    if(x=='A'&&y=='C')return true;
    if(x=='B'&&y=='C')return true;
    if(x=='D'&&y=='F')return true;
    return false;
}

bool near(char x,char y){
    if(x>y)swap(x,y);
    if(x=='A'&&y=='B')return true;
    if(x=='C'&&y=='D')return true;
    if(x=='D'&&y=='F')return true;
    return false;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int x,y;
    string a,b;
    cin>>x>>a>>y>>b;
    if(x!=y)cout<<"0000";
    else{
        cout<<1;
        if(a[0]!=b[0]||a[1]!=b[1])cout<<"000";
        else{
            cout<<1;
            if(!ck(a[2],b[2]))cout<<"00";
            else{
                cout<<1;
                if(!near(a[2],b[2]))cout<<0;
                else cout<<1;
            }
        }
    }
    return 0;
}
