#include <bits/stdc++.h>
using namespace std;
int a[1000005],cnt[1000005],flag[1000005],ans[1000005],flag2[1000005];
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
            flag[a[j]]=1;
            if(cnt[a[j]]==1){
                flag2[a[j]]=j;
            }
            if(cnt[a[j]]>1){
                 for(int z=flag2[a[j]];z<j;z++){
                    flag[a[z]]=0;
                    flag2[a[z]]=0;
                 }
                 flag[a[j]]=1;
                 flag2[a[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            cnt[j]=0;
            flag2[j]=0;
            if(flag[j]==1){
                ans[j]++;
                flag[j]=0;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
