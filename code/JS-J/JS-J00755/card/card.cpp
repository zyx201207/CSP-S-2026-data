#include <bits/stdc++.h>
#define int long long

using namespace std;
int n,mm;
int a[500005],ans[300005];
map<int,int> mp;
vector<int> v[500005];
struct node{
    int i;
    map<int,int> m;
};
node dfs(int x){
    if(v[x].empty()){
        node k;
        k.i=1;
        k.m[a[x]]=1;
        ans[a[x]]+=1;
        return k;
    }
    int sx=0;
    node sum;
    for(int i:v[x]){
        auto k=dfs(i);
        sx+=k.i;
        for(auto j:k.m) sum.m[j.first]+=j.second;
    }

    sum.i=sx+1;
    sum.i-=sum.m[a[x]];
    ans[a[x]]+=sum.i;
    sum.i+=sum.m[a[x]];
    sum.m[a[x]]+=sum.i;
   // cout<<x;
  //  cout<<sum.i<<ans[a[x]]<<sum.m[a[x]]<<endl;
    return sum;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
   // ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>mm;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mp[a[n]]=n;
    for(int i=n-1;i>=1;i--){
            int f;
        if(!mp[a[i]])mp[a[i]]=i,f=i+1;
        else f=mp[a[i]];
        v[f].push_back(i);
        //cout<<f[i]<<' ';
    }
   // cout<<endl;

    auto c=dfs(n);
    for(int i=1;i<=mm;i++) cout<<ans[i]<<' ';
cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
