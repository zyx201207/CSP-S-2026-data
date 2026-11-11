#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],cnt[3010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int flag[5010]={0},b[5010],s[5010];
        for(int j=i;j<=n;j++){
            b[j]=a[j];
            if(flag[b[j]]==0){
                flag[b[j]]=1;
                s[b[j]]=j;
            }
            else{
                for(int k=s[b[j]];k<j;k++){
                    flag[b[k]]=0;
                    b[k]=0;
                }
                flag[b[j]]=1;
                s[b[j]]=j;
            }
        }
        for(int j=1;j<=m;j++){
            if(flag[j]==1){
                cnt[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
