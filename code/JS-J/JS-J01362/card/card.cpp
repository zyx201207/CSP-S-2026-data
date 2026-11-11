#include<bits/stdc++.h>
using namespace std;
int a[500001];
int cnt[500001];
int cntw[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n+1;i++){
            memset(cntw,0,sizeof(cntw));
        for(int j=i-1;j<=n;j++){
            if(cntw[a[j]]==0){
                cntw[a[j]]++;
            }
            else{
                memset(cntw,0,sizeof(cnt));
            }
        }
        for(int j=1;j<=m;i++){
            if(cntw[j]==1){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
