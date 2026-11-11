#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans=1;
int a[999999];
int b[999999];
void dfs(int step){
    if(step>m){
    return;
    }
    for(int i=1;i<=n;i++){
    b[i]=a[i]-a[i-1];
    step=step+b[i];
    if(a[i]=a[i-1]+b[i]){
    ans++;
    }dfs(step+b[i]);
    dfs(step-b[i]);
    }

}
int main(){
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];
}
dfs(0);cout<<ans;
return 0;
}
