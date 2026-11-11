#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],mx,ans,mx_ans,used[200005];
vector<int> v;
void dfs(int sum){
    if(sum==m){
            int k=v[0];
        for(int i=1;i<v.size();i++){
            k&=v[i];
        }
        mx_ans=max(mx_ans,k);
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i]==0){
            used[i]=1;
            v.push_back(a[i]);
            dfs(sum+1);
            v.pop_back();
            used[i]=0;
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(m==1)
            mx=max(a[i],mx);
    }
    if(m==1){
        cout<<mx;
        return 0;
    }
    if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    dfs(0);
    cout<<mx_ans;
    return 0;
}
