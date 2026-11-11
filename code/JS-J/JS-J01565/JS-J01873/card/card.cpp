#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],l[20006],ans[20005];
bool ap[20005],A1=1,A2=1,A3=1,ti[20005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        l[a[i]]=i;
        if(a[i]<a[i-1])A1=0;
        if(a[i]>a[i-1])A2=0;
        if(ap[a[i]])A3=0;
        ap[a[i]]=1;
    }
    if(A1||A2||A3){
        for(int i=1;i<=m;i++)
            if(ap[i])cout<<l[i]<<' ';
            else cout<<0<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)ti[j]=0;
        for(int j=i;j<=n;j++){
            if(ti[a[j]]){
                for(int k=j-1;a[k]!=a[j];k--)ti[a[k]]=0;
            }
            ti[a[j]]=1;
        }
        for(int j=1;j<=m;j++)ans[j]+=ti[j];
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
