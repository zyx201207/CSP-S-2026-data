#include<bits/stdc++.h>
using namespace std;
int na[31];//num_in_bin
int n,ans=0,m;
int dfs(int k,int t){
    if(k>m)return INT_MAX;
    int pa=-1,a;
    for(int i=t;i<=n-m+k;i++){
       a= dfs(k+1,i)&na[t];
       pa=max(a,pa);
    }return a;
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    int maxm=-1;
    for(int i=1;i<=n;i++){
        cin>>na[i];
        maxm=max(na[i],maxm);
    }
    if(n<=20||m==2||m==n){
        cout<<dfs(1,1);
    }else if(m=1){
        cout<<maxm;
    }
    return 0;
}

