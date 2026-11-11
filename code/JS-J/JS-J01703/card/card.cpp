#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int b[300010]={0};
int m,n;
signed main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    cin>>n>>m;
     for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++){
      int f[500010]={0};
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(a[k]==a[j]){
                      for(int s=j;s<k;s++){
                            f[s]=1;
                      }
                      j=k;
                      continue;
                }
            }
        }
        for(int j=i;j<=n;j++){
           if(f[j]==0){
                b[a[j]]++;

           }
        }
    }cout<<endl;
     for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
     }
   return 0;
}
