#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],f[M],moni[N],cnt[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    int r=1;
    for(int j=1;j<=n;j++){
        memset(f,0,sizeof(f));
        for(int i=j;i<=n;i++){
            if(f[a[i]]==1){
                while(moni[r]!=a[i]) r--;
            }else moni[r]=a[i],f[a[i]]=1,r++;
        }
        while(r!=1) r--,cnt[moni[r]]++;
    }
    for(int j=1;j<=m;j++) cout<<cnt[j]<<" ";
    return 0;
}
