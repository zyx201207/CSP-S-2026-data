#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k[500005],pd[300005],re[500005];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        int t=1;
        for(int j=i;j<=n;j++){
            if(pd[a[i]]==0){
                pd[a[i]]=t; k[t]=a[i];
                t++;
            }
            else{
                for(int j=pd[a[i]]+1;j<t;j++){
                    pd[j]=0; k[j]=0;
                }
                t=pd[a[i]]+1;
            }
        }
        for(int j=i;j<=n;j++){
            if(k[j]) re[k[j]]++;
            pd[j]=0; k[j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        if(re[i]) cout<<re[i]<<' ';
    }
    return 0;
}
