#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010];
int ans[500010];
vector<int>c;
int bfind(int x){
    for(int i=0;i<c.size();i++){
        if(c[i]==x)return i;
    }
    return -1;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        int x=a[i];
        int q=bfind(x);
        if(q!=-1){
            q=n-q;
            for(int k=i;k<q;k++){
                c.pop_back();
            }
        }
        c.push_back(x);
        for(int i=0;i<c.size();i++){
            ans[c[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
}
