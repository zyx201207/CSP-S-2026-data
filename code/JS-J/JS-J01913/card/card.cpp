#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],mcx[300005];
signed main()
{
  //  freopen("card.in","r",stdin);
 //   freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=i;j<=n;j++){
            int flag=1;
            for(int k=cnt;k>=1;k--){
                if(b[k]==a[j]){
                    flag=0;
                    cnt=k;
                    break;
                }
            }
            if(flag==1){
                b[++cnt]=a[j];
            }
        }
        for(int j=1;j<=cnt;j++){
            mcx[b[j]]++;
            b[j]=0;

        }

    }
    for(int i=1;i<=m;i++) cout<<mcx[i]<<" ";
    return 0;
}
