#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int p[200005],a[200005];
int n,m;
int dfs(int q,int cnt){
if(q==0){
    ans=max(ans,cnt);
    return 0;
}
for(int i=1;i<=n;i++){
    if(p[i]==0){
        if(cnt==0){
            p[i]=1;
            dfs(q-1,a[i]);
            p[i]=0;
        }
        else {
            p[i]=1;
            dfs(q-1,(cnt&a[i]));
            p[i]=0;
        }
    }
}
return 0;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
dfs(m,0);
cout<<ans;
return 0;
}
