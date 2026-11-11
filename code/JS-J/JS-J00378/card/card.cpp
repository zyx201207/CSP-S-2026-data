#include<bits/stdc++.h>
using namespace std ;
#define int long long
int n,m,cnt[1010111];
vector<int> a,b;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;i++){
        vector<int> b;
        for(int j=i;j<=n;j++){
            for(int k=0;k<b.size();k++){
                if(b[k]==a[j]&&b[k]!=0){
                    for(int u=b.size()-1;b[k]==a[j]&&b[k]!=0;u--){
                        b[u]=0;
                    }
                }
            }
            b.push_back(a[j]);
        }
        for(int j=0;j<b.size();j++){
            cnt[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
    return 0;
}
