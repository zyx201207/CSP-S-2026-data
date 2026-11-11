#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn=0;
void dfs(int dep,long long sum,int front1){
    if(dep>m){
        maxn=max(maxn,sum);
        return ;
    }
    for(int i=front1+1;i<=n-(m-dep);i++){
            if(dep==1){
                dfs(dep+1,a[i],i);
            }else{
                dfs(dep+1,a[i]&sum,i);
            }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<maxn<<endl;
    return 0;
}
