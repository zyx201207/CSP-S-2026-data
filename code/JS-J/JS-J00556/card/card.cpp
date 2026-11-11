#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],z[5005],k,f[3005][3],s[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m==1){
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        k=0;
        memset(f,0,sizeof(f));
        for(int j=i;j<=n;j++){
            if(f[a[j]][1]==1){
                for(int l=f[a[j]][2]+1;l<=k;l++){
                    f[z[l]][1]=0;
                }
                k=f[a[j]][2];
            }
            else{
                k++;
                f[a[j]][1]=1;
                f[a[j]][2]=k;
                z[k]=a[j];
            }
        }
        for(int j=1;j<=k;j++){
                s[z[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }
return 0;
}
