#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[300005];
int sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int d = 0;
        memset(c,0x3f,sizeof c);
        for(int j=i;j<=n;j++){
            b[++d] = a[j];
            if(c[a[j]]!=0x3f3f3f3f){
                for(int k=c[a[j]]+1;k<d;k++){
                    c[b[k]] = 0x3f3f3f3f;
                }
                d = c[a[j]];
            }else{
                c[a[j]] = d;
            }
        }
        for(int j=1;j<=d;j++){
            sum[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
