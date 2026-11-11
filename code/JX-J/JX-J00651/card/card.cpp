#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],b[500005],ans[300005];
vector <int>c[300005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]].push_back(i);
    }
    for(int i=1;i<=m;i++){
		int l=c[i].size();
        for(int j=0;j<l-1;j++){
            b[c[i][j]]=c[i][j+1];
        }
        b[c[i][l-1]]=c[i][l-1];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            while(b[j]!=j){
                j=b[j];
            }
            ans[a[j]]+=1;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
