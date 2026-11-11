#include <bits/stdc++.h>
using namespace std;
/*
int f(int l,int r){
    int mid=(l+r)>>1;
    if(l==r)return mid;
    if(){l=mid;return(l,r);}
    else{r=mid;return(l,r);}
}
*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1,a2;
    string s1,s2;
    cin>>a1>>s1>>a2>>s2;
    int x=(s1[0])*10+s1[1];
    int y=(s2[0])*10+s2[1];
    if(a1!=a2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(x!=y){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(s1[2]=='F'){
        if(s2[2]=='D'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(s1[2]=='D'){
        if(s2[2]=='F'){
            cout<<"11";
            return 0;
        }
        else{
            cout<<"00";
            return 0;
        }
    }
    else if(s2[2]=='D'&&s2[2]=='F'){
        cout<<"00";
        return 0;
    }
    if((s2[2]=='D'&&s1[2]=='C')||(s2[2]=='C'&&s1[2]=='D')){
        cout<<"00";
        return 0;
    }
    cout<<1;
    if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
        cout<<1;
        return 0;
    }
    cout<<0;
    return 0;
}
