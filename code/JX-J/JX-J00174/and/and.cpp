#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,ans=INT_MIN;
int a[N];
void dfs(int i,int cnt,int sum){
    if(i<n || cnt>m){
        ans=max(ans,sum);
    }
    dfs(i+1,cnt+1,sum and a[i]);
    dfs(i+1,cnt,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,1,a[i]);
    }
    cout<<a[3];
    return 0;
}
