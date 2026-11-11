#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,a[10005];
long long c[300005], sum[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        string q;
        for(int j=i;j<=n;j++){
            if(c[a[j]]!=0){
                memset(c,0,sizeof(c));
            }
            c[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(c[j]==1){
                sum[j]++;
            }
        }
        memset(c,0,sizeof(c));
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
