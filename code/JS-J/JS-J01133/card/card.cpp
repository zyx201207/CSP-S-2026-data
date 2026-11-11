#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a[500005],tong[300005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int t[500005];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          t[j]=a[j];
        }
        for(int j=i;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(t[k]==t[j]){
                    for(int l=j;l<k;l++){
                        t[l]=-1;
                    }
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(t[j]!=-1) tong[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<tong[i]<<" ";
    }
    return 0;
}
