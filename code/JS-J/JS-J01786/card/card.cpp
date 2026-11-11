#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],t,ans[500010];
void nb(int i1){
    for(int j=i1;j<=n;j++){
            bool h=false;
            long long t1=t;
            for(int k=1;k<t;k++){
                if(b[k]==a[j]){
                    t1=k;
                    h=true;
                }
                if(h)b[k]=-1;
            }
            t=t1;
            b[t]=a[j];
            t++;
        }
}
void nnb(){
    for(int p=1;p<=m;p++){
        for(int w=1;w<t;w++){
            if(b[w]==p){
                ans[p]++;
                break;
            }
        }
    }
}
void nnnb(){
    for(int ii=1;ii<=n;ii++){
        b[ii]=-1;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=-1;
        ans[i]=0;
    }
    for(int i=1;i<=n;i++){
        t=1;
        nb(i);
        nnb();
        nnnb();
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
