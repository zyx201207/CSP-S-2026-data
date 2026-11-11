#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
       ans[a[i]]++;
       if(i!=1&&p[a[i-1]]==i-1)ans[a[i]]+=ans[a[i-1]];
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
