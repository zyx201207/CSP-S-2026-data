#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005],d[300005],ans[300005];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long b[500005]={0};
        for(int j=i;j<=n;j++){
            b[j]=a[j];
            c[a[j]]+=1;
            if(c[a[j]]==1)d[a[j]]=j;
            if(c[a[j]]!=1){
                for(int k=d[a[j]];k<j;k++){
                    c[b[k]]=0;
                    b[k]=0;
                }
                c[a[j]]=1;
                d[a[j]]=j;
                continue;
            }
        }
        for(int p=1;p<=n;p++){
            if(b[p]!=0)ans[b[p]]+=1;
            c[p]=0;
            d[p]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";

return 0;
}
