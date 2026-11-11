#include<bits/stdc++.h>
using namespace std;
int a[500010],f[500010],p[500010];
void die(int l,int r){
    for(int i=l;i<=r;i++){
        f[i]=0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]=i;
        if(a[i]<a[i-1]&&i!=1){
            flag=0;
        }
    }
    if(flag==1){
        for(int i=1;i<=m;i++){
            cout<<p[i]<<' ';
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        int ans=0;
        for(int k=1;k<=n;k++){
            for(int j=1;j<=500001;j++){
                f[j]=1;
            }
            for(int j=k;j<=n;j++){
                for(int o=k;o<j;o++){
                    if(a[o]==a[j]&&f[o]!=0){
                        die(o,j-1);
                    }
                }
            }
            for(int j=k;j<=n;j++){
                if(a[j]==i&&f[j]==1){
                    ans++;
                    break;
                }
            }
        }
        cout<<ans<<' ';
    }
    return 0;
}
