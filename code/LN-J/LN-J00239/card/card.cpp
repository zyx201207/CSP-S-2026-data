#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c[200005],x,z,g=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    x=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(x--){
        z=1;
        for(int i=g;i<=n;i++){
            b[z]=a[i];
            if(b[z-1]==b[z]){
                b[z]=0;
                z--;
            }
            z++;
        }
        for(int i=1;i<=z;i++){
            c[b[i]]++;
        }
        g++;
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

