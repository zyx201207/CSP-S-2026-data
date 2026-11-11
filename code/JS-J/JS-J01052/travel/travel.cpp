#include<bits/stdc++.h>
using namespace std;
int c1x,c1z,c2x,c2z;
char c1s,c2s;
bool ans1,ans2,ans3;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1x>>c1z>>c1s>>c2x>>c2z>>c2s;
    if(c1x==c2x){
        ans1=true;cout<<1;
    }     
    else{
       ans1=false; cout<<0;
    } 
    if(ans1 && c1z==c2z){
        ans2=true;
        cout<<1;
    } 
    else{
        ans2=false;
        cout<<0;
    } 

    if(ans1 && ans2){
        if((c1s=='A' || c1s=='B' || c1s=='C') && (c2s=='A' || c2s=='B' || c2s=='C')){
            ans3=true;
            cout<<1;
        }
        else if((c1s=='D' || c1s=='F' ) && (c2s=='D' || c2s=='F' )){
            ans3=true;
            cout<<1;
        }
        else{
            ans3=false;
            cout<<0;
        }
    }else{
        ans3=false;
        cout<<0;
    }

    if(ans3 && abs(c1s-c2s)==1){
        cout<<1;
    }
    else{
        cout<<0;
    }
    cout<<"\n";
    return 0;
}