#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string h="";
    long long w=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        char t;
        cin>>m>>t;
        w+=m;
        for(int j=1;j<=m;j++){
            h+=t;
        }
    }
    long long x=w/2,y=w/2;
    if(w%2==1){
        y++;
    }
    string ll="";
    for(int i=0;i<x;i++){
        ll+=h[i];
    }
    long long ans=0;
    long long k=0;
    for(int i=y;i<w;i++){
        if(ll[k++]!=h[i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
