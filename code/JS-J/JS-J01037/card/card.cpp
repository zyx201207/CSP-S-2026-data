#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    cin>>n>>m;
    int a[n+5],gzy[m+5]={0};
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int _=1;_<=n;_++){
        int b[n+5]={0};
        for (int i=_;i<=n;i++){
        bool flag=false;
            for (int j=_;j<i;j++){
                if (b[j]==a[i]){
                    flag=true;
                }
                if (flag) b[j]=0;

            }
            b[i]=a[i];
        }
        for (int i=1;i<=n;i++){
            if (b[i]) gzy[b[i]]++;
        }
    }
    for (int i=1;i<=m;i++){
      cout<<gzy[i]<<' ';
    }
    return 0;
}
