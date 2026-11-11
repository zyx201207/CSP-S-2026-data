#include<bits/stdc++.h>
using namespace std;
int a[500010];
int cnt[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                cnt[a[j]]++;
            for(int k=j+1;k<=n;k++){
                if(a[k]==a[j]){
                    j=k-1;
                    cnt[a[k]]--;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
