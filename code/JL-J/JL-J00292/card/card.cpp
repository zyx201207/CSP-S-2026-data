#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],p[600000],ans=0;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int j=1;j<=m;j++){
        ans=0;
        for(int i=j;i<=n;i++){
            bool f=true;
            int k;
            for(int m=1;m<=n;m++){
                if(p[m]==a[i]){
                    f=false;
                    k=m;
                    break;
                }
            }
            if(f) p[i]=a[i];
            else{
                for(int m=k;m<=n;m++){
                    p[m]=0;
                }
                p[k]=a[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(p[i]==j) ans++;
            p[i]=0;
        }
        cout<<ans<<" ";
    }
    return 0;
}
