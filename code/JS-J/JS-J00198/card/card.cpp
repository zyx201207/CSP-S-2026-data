#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005];
vector<int>v;
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    bool isA=true;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)if(a[i]<a[i-1])isA=false;
    if(isA){
        for(int i=1;i<n;i++){
            if(a[i]!=a[i+1])ans[a[i]]=i;
        }
        ans[a[n]]=n;
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++){
        v.clear();
        for(int j=i;j<=n;j++){
            int pos=-1;
            for(int k=0;k<v.size();k++)if(v[k]==a[j]){
                pos=k;
                break;
            }
            if(pos==-1)v.push_back(a[j]);
            else{
                int x=v.size();
                for(int k=pos;k<x;k++)v.pop_back();
                v.push_back(a[j]);
            }
        }
        set<int>s;
        for(int j=0;j<v.size();j++){
            if(!s.count(v[j])){
                ans[v[j]]++;
                s.insert(v[j]);
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
