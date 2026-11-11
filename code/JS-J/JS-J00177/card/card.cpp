#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int cnt[300005];
bool f[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            f[j]=true;
            for(int k=j;k>=i+1;k--){
                if(a[j]==a[k]&&f[k]){
                    for(int p=k;p<j;p++){
                        f[p]=false;
                    }
                }
            }
        }
        for(int j=i+1;j<=n;j++){
            if(f[j]){
                cnt[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
