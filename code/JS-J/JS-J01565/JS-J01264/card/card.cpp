#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=5e5+10;
int n,m,a[MAXN],cnt[MAXN];
int r;
int tmp[MAXN];
signed main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
      cin>>n>>m;
      for(int i=1;i<=n;i++){
         cin>>a[i];
         tmp[i]=a[i];
      }
      if(m==1){
         cout<<n;
         return 0;
      }
      if(m==2){
        for(int i=1;i<=n;i++){
            cnt[a[i]]++;
        }
        if(a[n]==1) cout<<n<<" "<<cnt[2];
        else        cout<<cnt[1]<<" "<<n;
        return 0;
      }
      else{
        for(int i=1;i<=n;i++){
              r=n;
              for(int l=1;l<=n;l++) a[i]=tmp[i];
              for(int j=i;j<=n;j++){
                bool f=false;
                int t;
                for(int k=i;k<=r;k++){
                    if(a[k]==a[j]){
                        f=true;
                        t=k;
                        break;
                    }
                }
                if(f){
                    r=t;
                    a[t]=a[j];
                }
                else{
                    r++;
                    a[r]=a[j];
                }
            }
            for(int p=i;p<=r;p++){
                cnt[a[p]]++;
            }
        }
        for(int i=1;i<=m;i++){
         cout<<cnt[i]<<" ";
        }
        return 0;
      }
      return 0;
}

