#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],b[500005],cnt[300005];
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i],b[i]=a[i];
    for (int j=1;j<=n;j++){
        for (int i=j;i<=n;i++){
            for (int t=j;t<i;t++)
                if (a[t]==a[i])
                    for (int k=t;k<i;k++)
                        a[k]=-2;

        }
        for (int i=j;i<=n;i++)
            if (a[i]!=-2)
                cnt[a[i]]++;
            else
                a[i]=b[i];
    }
    for (int i=1;i<=m;i++)
        cout<<cnt[i]<<" ";
    return 0;
}
