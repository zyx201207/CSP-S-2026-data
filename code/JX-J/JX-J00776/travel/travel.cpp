#include<bits/stdc++.h>
using namespace std;

char a[10]={'A','B','C','D','F'};
string r,x,r1,x1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>r1>>x>>x1;
    if(r!=x){
        for(int i=0;i<4;i++)cout<<0;
        return 0;
    }
    else cout<<1;
    if(r1[0]!=x1[0]||r1[1]!=x1[1]){
        for(int i=0;i<3;i++)cout<<0;
        return 0;
    }
    else cout<<1;
    int p,q;
    for(int i=1;i<=5;i++){
        if(r1[2]==a[i-1]){
            p=i;
        }
        if(x1[2]==a[i-1]){
            q=i;
        }
    }
    if(p<=3&&q>3||p>3&&q<=3){
        for(int i=0;i<2;i++)cout<<0;
        return 0;
    }
    else cout<<1;
    if(p==q+1||q==p+1)cout<<1;
    else cout<<0;
    return 0;
}
