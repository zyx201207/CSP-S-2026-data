#include<bits/stdc++.h>
using namespace std;
int m,n,a[20020],cnt[20020];
bool f[20020];
vector<int> x;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::ios::sync_with_stdio();
    std::cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int k=1;k<=n;k++){
        x.clear();
        for(int i=1;i<=m;i++){
            f[i]=0;
        }
        for(int i=k;i<=n;i++){
            if(!f[a[i]]){
                f[a[i]]=1;
                x.push_back(a[i]);
            }
            else{
                while(x[x.size()-1]!=a[i]){
                    f[x[x.size()-1]]=0;
                    x.pop_back();
                }
            }
        }
        for(int i=0;i<x.size();i++){
            cnt[x[i]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}
