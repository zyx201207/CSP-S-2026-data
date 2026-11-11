#include<bits/stdc++.h>
using namespace std;
int n,m,a[514514],q[314514],ans[514514],l,s[514514],p,b[514514],r=1;
bool c[314514],f=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1&&a[i]<a[i-1]) f=0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]) s[++p]=i,b[p]=a[i];
    }
    if(f){
        for(int i=1;i<=p;i++) cout<<s[i]<<" ";
        return 0;
    }
    if(m==2){
        if(a[n]==1){
            ans[1]=n;
            for(int i=1;i<n;i++){
                if(a[i]==2) ans[2]++;
            }
        }
        else {
            ans[2]=n;
            for(int i=1;i<n;i++){
                if(a[i]==1) ans[1]++;
            }
        }
        cout<<ans[1]<<" "<<ans[2];
        return 0;
    }
    if(n<=500&m<=200){
        for(int i=1;i<=n;i++){
            memset(c,0,sizeof(c));
            l=0;
            for(int j=i;j<=n;j++){
                for(int k=1;k<=l;k++){
                    if(q[k]==a[j]){l=k-1;break;}
                }
                q[++l]=a[j];
            }
            for(int j=1;j<=l;j++) c[q[j]]=1;
            for(int j=1;j<=m;j++) ans[j]+=c[j];
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
        return 0;
    }
    for(int i=1;i<=p;i++){
        memset(c,0,sizeof(c));
        l=0;
        for(int j=i;j<=p;j++){
            if(c[b[j]]){
                for(int k=1;k<=l;k++){
                    if(q[k]==b[j]){l=k-1;break;}
                }
            }
            q[++l]=b[j];c[b[j]]=1;
        }
        memset(c,0,sizeof(c));
        for(int j=1;j<=l;j++) c[q[j]]=1;
        for(int j=1;j<=m;j++) ans[j]+=((s[i]-s[i-1])*c[j]);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
