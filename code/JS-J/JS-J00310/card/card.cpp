#include<bits/stdc++.h>
#define ican using
#define ak namespace
#define cspj std;
ican ak cspj
int n,m;
int a[600005],pos[600005];
int mm[600005],ans[600005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        mm[a[i]]++;
        if(mm[a[i]]==1){
            pos[a[i]]=i;
        }
        int j=i;
        while(j<=n){
            if(j==pos[a[j]]){
                ans[a[j]]++;
                j++;
            }
            else{
                j=pos[a[j]];
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
