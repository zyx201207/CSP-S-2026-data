#include<bits/stdc++.h>
using namespace std;
int hsh[300005];
int a[500005];
int n,m;
int fd(int st,int val){
    int p=st;
    while(p!=n+1&&a[p]!=val) p++;
    return p;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        int pos=i;
        while(pos!=n+1){
            int p=fd(pos+1,a[pos]);
            while(p<=n){
                pos=p;
                p=fd(pos+1,a[pos]);
            }
            hsh[a[pos]]++;
            pos++;
        }
    }
    for(int i=1;i<=m;++i){
        cout<<hsh[i]<<' ';
    }
    return 0;
}
