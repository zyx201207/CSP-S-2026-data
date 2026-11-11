#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M],lst[M];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)lst[i]=2e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        bool pl[M];
        for(int j=1;j<=m;j++)pl[j]=0;
        for(int j=i;j<=n;j++){
            int k=a[j];
            if(pl[k]==0)ans[k]++,pl[k]=1;
            if(lst[k]==2e9)lst[k]=j;
            if(lst[k]!=2e9){
                j=lst[k];
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
