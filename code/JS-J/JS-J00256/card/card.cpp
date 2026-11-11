#include<bits/stdc++.h>
using namespace std;
int cnt[500005];
bool f[500005]={};
int a[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f[a[j]]!=0){
                    for(int k=j;k>=0;k++){
                        f[a[k]]==0;
                        if(a[k]==a[j]){
                            break;}
                }
            }
            f[a[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(f[j]!=0){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<(i==m?"":" ");
    }
    return 0;
}
