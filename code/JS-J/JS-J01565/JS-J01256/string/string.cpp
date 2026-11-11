#include<bits/stdc++.h>
using namespace std;
#define int long long
struct nm{
    int q;
    char w;
};
    string h;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    nm a[200005];
    int fin=0;
    int p=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].q>>a[i].w;
        for(int j=1;j<=a[i].q;j++){
            
            h[p]=a[i].w;
            p++;
        }
    }
    int y=p/2;
    int ty=y;
    for(int i=1;i<=y;i++){
        if(h[i]==h[p-i])ty--;
    }
    cout<<ty;
    return 0;
}