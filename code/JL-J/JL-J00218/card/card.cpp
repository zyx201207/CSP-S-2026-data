#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=2e5+5;

int n,m;
int a[N];
int b[N];
int ans[N];

signed main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int k=1;k<=n;k++){//round

        for(int i=1;i<=n;i++)
            b[i]=a[i];

        for(int i=k;i<=n;i++){//now
            for(int j=k;j<i;j++){//first

                if(b[j]==b[i]){
                    for(int g=j;g<i;g++)
                        b[g]=0;
                }
            }

        }
        for(int i=k;i<=n;i++)
            if(b[i]) ans[b[i]]++;
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';

    return 0;
}
