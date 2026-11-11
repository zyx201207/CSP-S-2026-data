#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,ans=-1;
int a[10000000];
int cnt[100];
void dfs(int i,int num,int pans){
if(num>=m||i>n){
        if(num<m)return;
cout<<pans<<" "<<cnt[0]<<cnt[1]<<cnt[2]<<cnt[3]<<cnt[4]<<cnt[5]<<cnt[6]<<cnt[7]<<cnt[8]<<cnt[9]<<endl;
    ans=max(ans,pans);
return;
}
dfs(i+1,num,pans);
cnt[num]=a[i];
if(num==0){
dfs(i+1,num+1,a[i]);
}else{
dfs(i+1,num+1,pans&a[i]);
}
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
}if(m==1){
      ans=a[1];
    for(int i=2;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}else if(n==m){
    ans=a[1];
    for(int i=2;i<=n;i++){
        ans&=a[i];
    }
    cout<<ans;
    return 0;
}else {
dfs(1,0,0);
cout<<ans;
}
return 0;
}
