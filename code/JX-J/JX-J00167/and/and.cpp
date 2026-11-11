#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[32],ans,tot,p,k;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    c[0]=1;
    for(int i=1;i<=30;i++){
        c[i]=c[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=30;i>=0;i--){
        tot=0;
        for(int j=1;j<=n;j++){
            k=a[j]&c[i];
            if(k==c[i]){
                tot++;
            }
        }
        if(tot>=m){
            p=0;
            ans|=c[i];
            for(int j=1;j<=n;j++){
                k=a[j]&c[i];
                if(k==c[i]){
                    a[++p]=a[j];
                }
            }
            n=tot;
        }
    }
    cout<<ans<<endl;
    return 0;
}
