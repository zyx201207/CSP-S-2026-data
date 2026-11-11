#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    long long a[300005],ans[300005];
    bool b[100005];
    cin>>n>>m;
    vector<long long> q[100005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long sum=0;
    for(int i=n;i>=1;i--){
        if(!b[a[i]]){
            q[a[i]].push_back(a[i]);
            ans[a[i]]++;
            for(auto j:q[a[i+1]]){
                q[a[i]].push_back(j);
                ans[j]++;
            }
            b[a[i]]=1;
        }else{
            for(auto j:q[a[i]]) ans[j]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
