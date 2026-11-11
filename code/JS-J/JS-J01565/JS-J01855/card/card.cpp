#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[500001];
bool flag=1;
map<int,int>mp;
int main(){
freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if (a[i]<a[i-1])
            flag=0;
    }
    if (flag==1){
        for (int i=1;i<=n;i++){
            if (a[i]!=a[i+1]){
                printf("%d ",i);
            }
        }
        return 0;
    }
    for (int i=1;i<=n;++i){
        for (int j=i;j<=n;++j){
            if (!mp[a[j]]){
                mp[a[j]]=j;
            }
            else{
                for (int l=mp[a[j]];l<j;l++){
                    mp[a[l]]=0;
                }
                mp[a[j]]=j;
            }
        }
        for (int l=1;l<=m;l++){
            if (mp[l])
                ans[l]++;
            mp[l]=0;
        }
    }
    for (int i=1;i<=m;++i){
        printf("%d ",ans[i]);
    }
    return 0;
}
/*

*/
