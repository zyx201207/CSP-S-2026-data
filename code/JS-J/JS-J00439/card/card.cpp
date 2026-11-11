#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],b[MAXN<<1];
int cnt[300005];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i]=a[i];
        }
        for(int j=i;j<=n;j++){
            for(int k=1;k<=n;k++){
                 if(flag){
                     b[k]=0;
                     continue;
                }
                 if(b[k]==a[j]){
                    flag=1;
                 }
            }
            if(!flag){
                b[n+1]=a[j];
            }
        }
        for(int j=1;j<=MAXN<<1;j++){
            cnt[b[j]]++;
        }
    }
    for(int i=1;i<m;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<cnt[m];
    return 0;
}
