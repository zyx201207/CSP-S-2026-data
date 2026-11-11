#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],la[500005];
int s[500005];
int k[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,fl = 0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        k[a[i]] = i;
        if(a[i] < a[i-1]) fl = 1;
    }
    if(!fl){
        for(int i=1;i<=m;++i){
            cout<<k[i]<<'\n';
        }
    }
    else{
        for(int i=1;i<=n;++i){
            la[i] = -1;
            for(int j=i;j<=n;++j){
                if(a[j] == a[i]) la[i] = j;
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=i;j<=n;++j){
                if(la[j] != -1) j = la[j];
                s[a[j]]++;
            }
        }
        for(int i=1;i<=m;++i){
            cout<<s[i]<<' ';
        }
    }
    return 0;
}
