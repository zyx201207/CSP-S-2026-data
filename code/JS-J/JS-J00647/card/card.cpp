#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,sum[500010];
struct node{
    long long c;
    long long w;
}v[500010],v2[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[a[i]].c++;
        v[a[i]].w=i;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++){
            v2[a[k]].c=v[a[k]].c;
            v2[a[k]].w=v[a[k]].w;
        }
        for(int j=0;j<i;j++){
            v2[a[j]].c=v2[a[j]].c-1;
        }
        for(int r=n;r>=i;r--){
            if(v2[a[r]].c>=2){
                for(int l=i;l<v2[a[r]].w;l++){
                    v2[a[l]].c-=1;
                }
            }
        }
        for(int t=i;t<=n;t++){
            sum[a[t]]+=v2[a[t]].c;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
