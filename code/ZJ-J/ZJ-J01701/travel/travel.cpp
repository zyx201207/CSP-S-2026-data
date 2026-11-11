#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b;
char q,w,e,r,t,y;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>a>>q>>w>>e>>b>>r>>t>>y;
    if(a==b){
        cout<<1;
    }else{
        cout<<"0000";
        return 0;
    }
    if(q==r&&w==t){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(e=='A'&&y=='B'){
        cout<<"11";
    }else if(e=='A'&&y=='C'){
        cout<<"10";
    }else if(e=='B'&&(y=='C'||y=='A')){
        cout<<"11";
    }else if(e=='C'&&y=='B'){
        cout<<"11";
    }else if(e=='C'&&y=='A'){
        cout<<"10";
    }else if(e=='E'&&y=='F'){
        cout<<"11";
    }else if(e=='F'&&y=='E'){
        cout<<"11";
    }else{
        cout<<"00";
    }
    return 0;
}
