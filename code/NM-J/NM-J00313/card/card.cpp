#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],ans[300010],one[300010],wei[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    queue <int> table;
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            if(one[a[i]]==1){
                for(int j=1;j<=table.size()-wei[a[i]]+1;j++){
                    one[table.front()]=0;
                    table.pop();
                }
            }
            table.push(a[i]);
            one[a[i]]=1;
            wei[a[i]]=table.size();
        }
        for(int i=1;i<=m;i++){
            ans[i]+=one[i];
            one[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
