#include<bits/stdc++.h>
using namespace std;
int n,m,f[300009],lst[500009],a[500009],cnt[500009];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(f[a[i]]!=0){
            lst[f[a[i]]]=i;
            f[a[i]]=i;
        }
        f[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;){
            if(lst[j]==0){
                cnt[a[j]]++;
                j++;
                continue;
            }
            j=lst[j];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
