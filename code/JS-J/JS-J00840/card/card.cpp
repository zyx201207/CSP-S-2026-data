#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++)cin>>a[i];
    if(n<=5000){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
               int f=0;
               for(int k=1;k<=j-i;k++)
              {
                  if(b[k]==a[j])f=k;
                  if(f)b[k]=0;
              }
              if(f)b[f]=a[j];
              else for(int k=j-i;k>=1;k--){if(b[k]!=0)b[k+1]=a[j];break;}
            }
            for(int k=1;b[k];k++)ans[b[k]]++;
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}
