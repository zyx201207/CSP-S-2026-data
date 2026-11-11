#include<bits/stdc++.h>
using namespace std;
int n,m;
int w=INT_MIN;
int num[200005];
int jis[200005];
void df(int a,int n1){
    if(a>m){
        int d=INT_MAX;
        for(int i=1;i<=m;a++){
            d&=jis[i];
        }
        if(d>=w){
            w=d;
        }
        return;
    }
    if(a>n){
        return;
    }
    for(int i=n1+1;i<=n;i++){
        jis[a]=num[i];
        df(a+1,n1+1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }
    df(1,0);
    cout<<w;
    return 0;
}

