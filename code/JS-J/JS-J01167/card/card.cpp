#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],x[500005];
stack<int> stl;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=i;j<=n;j++){
            bool flag=0;
            for(int l=1;l<=num-1;l++){
                if(x[l]==a[j]) num=l-1;
            }
            x[++num]=a[j];
        }
        for(int j=1;j<=num;j++){
            ans[x[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
