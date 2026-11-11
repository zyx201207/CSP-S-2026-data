#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,mm;
    cin>>n>>mm;
    vector<int>v(n);
    unordered_map<int,int>m,ans;
    vector<vector<int>>a(n);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=n-1;i>=0;i--){
        if(i!=n-1)a[i]=a[i+1];
        if(m[v[i]])a[i]=a[m[v[i]]];
        else a[i].push_back(v[i]);
        for(auto c:a[i])ans[c]++;
        m[v[i]]=i;
    }
    for(int i=1;i<mm;i++)cout<<ans[i]<<' ';
    cout<<ans[mm]<<endl;
    return 0;
}
