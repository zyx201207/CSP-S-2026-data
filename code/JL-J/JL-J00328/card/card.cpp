#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N],ans[N];vector<int>v[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;bool f=1;
    for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<a[i-1])f=0;
    }
    if(f){
        for(int i=1;i<=n;i++)ans[a[i]]=i;
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++)v[a[i]].push_back(i);
    for(int s=1;s<=n;s++){
        for(int i=1;i<=m;i++)c[i]=0;
        for(int i=s;i<=n;i++){
            if(v[a[i]][v[a[i]].size()-1]>i)i=v[a[i]][v[a[i]].size()-1];
            c[a[i]]=1;
        }
        for(int i=1;i<=m;i++)if(c[i])ans[i]++;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
