#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[500010],num;
int ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        num=0;
        for(int j=1;j<=m;j++)b[j]=0;
        for(int j=i;j<=n;j++){
            if(b[a[j]]&&c[b[a[j]]]==a[j]&&num>=b[a[j]]){
                num=b[a[j]];
            }
            else{
                b[a[j]]=++num;
                c[num]=a[j];
            }
        }
        for(int i=1;i<=num;i++){
            ans[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
