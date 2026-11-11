#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,a[500005],b[300005]={ };
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    int c[300005]={ };
        for(int j=i;j<=n;j++){
            if(c[a[j]]==0)
                b[a[j]]++;
            c[a[j]]=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i]<<" ";
    }
    return 0;
}
