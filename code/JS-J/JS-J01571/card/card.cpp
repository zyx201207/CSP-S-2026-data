#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[300005];
int b[300005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
    int x=ans[a[i]];
    for(int j=1;j<=m;j++){
        ans[j]=ans[j]-x;
            if(ans[j]<0){
                ans[j]=0;
            }
    }
    ans[a[i]]=i;
}
for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
}
return 0;
}
