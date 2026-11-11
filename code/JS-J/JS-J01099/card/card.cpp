#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<int> a(n+3);

    for(int i=1;i<=n;++i) cin>>a[i];

    vector<int> ans(n+3);

    bool bl=1;
    for(int i=1;i<=n;++i){
        if(a[i-1]>a[i]) bl=0;
    }

    if(bl){
        vector<int> las(m+3);
        for(int i=1;i<=n;++i){
            las[a[i]]=i;
        }

        for(int i=1;i<=m;++i){
            cout<<las[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    

    for(int i=1;i<=n;++i){
        vector<bool> b(n+3,1);
        for(int j=i;j<=n;++j){
            for(int k=i;k<j;++k){
                if(b[k]&&a[k]==a[j]){
                    for(;k<j;++k){
                        b[k]=0;
                    }
                    break;
                }
            }
        }
        for(int j=i;j<=n;++j){
            if(b[j]) ans[a[j]]++;
        }
    }

    for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}