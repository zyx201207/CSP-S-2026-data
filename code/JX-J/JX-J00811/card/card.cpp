#include<bits/stdc++.h>
using namespace std;
long long n,m,fr,ba,a[500005],b[500005],c[300005],t[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        fr=1,ba=1;
        for(int j=1;j<=n;j++) b[j]=0;
        for(int j=i;j<=n;j++){
            if(t[a[j]]){
                for(int k=c[a[j]]+1;k<ba;k++) t[b[k]]=c[b[k]]=0;
                ba=c[a[j]]+1;
            }
            else t[a[j]]=1,b[ba]=a[j],c[a[j]]=ba,ba++;
        }
        for(int j=1;j<=m;j++) ans[j]+=t[j],t[j]=0,c[j]=0;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
