#include<bits/stdc++.h>
using namespace std;
int n,a[200010],m,p2[31];
bool vis[200010];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
int maxl=0,l2m,ans=0;
for(int i=1;i<=n;i++) cin>>a[i],maxl=max(maxl,a[i]);
p2[0]=1,l2m=log2(maxl);
for(int i=1;i<=30;i++) p2[i]=p2[i-1]*2;
for(int l=l2m;l>=0;l--){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]>=p2[l] && vis[i]==0) sum++;
    }
        if(sum>=m) ans+=p2[l];
        for(int i=1;i<=n;i++){
            if(a[i]<p2[l]) vis[i]=(sum>=m || vis[i]);
            else a[i]-=p2[l];
        }
}
cout<<ans;
return 0;
}
