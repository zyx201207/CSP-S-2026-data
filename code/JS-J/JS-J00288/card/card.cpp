#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],c[300010],l=0;
bool f[500010];
int d[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        l=0;
        for(int j=1;j<=n;j++){
            f[j]=false;
        }
        for(int j=i;j<=n;j++){
            if(!f[a[j]]){
                l++;c[l]=a[j];f[a[j]]=true;
            }else{
                for(int k=l;k>=1;k--){
                    if(c[k]==a[j]){
                        l=k;
                        break;
                    }
                    f[c[k]]=false;
                    c[k]=0;
                }
            }
        }
        for(int j=1;j<=l;j++){
            d[c[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<d[i]<<" ";
    }
    return 0;
}
