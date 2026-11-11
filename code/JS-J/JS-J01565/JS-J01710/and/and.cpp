#include<bits/stdc++.h>
using namespace std;
int a[200005],m,n;
int dfs(int num,int xb,int xb2){
if(num==m) return a[xb]&a[xb2];
if(xb>n||xb2>n) return 0;
return max(dfs(num+1,xb,xb2+1),dfs(num,xb+1,xb2+1));
}
int main(){
freopen ("and.in","r",stdin);
freopen ("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
cout<<dfs(1,1,1);
return 0;
}
