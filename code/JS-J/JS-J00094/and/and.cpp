#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int u[200005];
int sum;
void dfs(int c,int l){
    if(m==c){
        int sum1=u[0];
        for(int i=1;i<m;i++){
            sum1=sum1&u[i];
        }
        sum=max(sum,sum1);
        return ;
    }
    if(l==n)return ;
    u[c]=a[l];
    dfs(c+1,l+1);
    u[c]=0;
    dfs(c,l+1);
    return ;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0);
    cout<<sum;
    return 0;
}
