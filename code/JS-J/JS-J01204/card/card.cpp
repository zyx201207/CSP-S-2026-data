#include<bits/stdc++.h>
using namespace std;
int a[500005],p[500005],b[300005],c[500005],d[500005],ans[300005],cnt[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,e=0,f=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>d[i];
    for(int i=1;i<=n;i++){
        if(d[i]!=d[i-1])a[++e]=d[i];
        cnt[e]++;
    }
    if(m==2){
        ans[a[e]]=n;
        for(int i=1;i<e;i++)
            if(a[i]==a[e-1])ans[a[e-1]]+=cnt[i];
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
        return 0;
    }
    n=e;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1])f=0;
    if(f){
        for(int i=1;i<=n;i++){
            cnt[i]+=cnt[i-1];
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=n;i++){
        p[i]=b[a[i]];
        b[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++)c[j]=0;
        for(int j=i;j<=n;j++)c[j]=1;
        for(int j=i;j<=n;j++){
            if(c[p[j]]!=0){
                for(int k=p[j];k<j;k++)c[k]=0;
            }
        }
        for(int j=1;j<=n;j++)ans[a[j]]+=c[j]*cnt[i];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
