#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        vector<int> b;
        for(int j=i;j<=n;j++){
            bool f=0;
            for(auto k=b.begin();k<b.end();k++){
                if(f) *(k)=0;
                if(*(k)==a[j]){
                    *(k)=0;
                    f=1;
                }
            }
            b.push_back(a[j]);
        }
        for(auto k=b.begin();k<b.end();k++){
            if(*(k)!=0) ans[*(k)]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}