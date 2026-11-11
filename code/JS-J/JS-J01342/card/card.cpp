#include<bits/stdc++.h>
using namespace std;
struct c{
int v;
int q;
}cnt[300005];
int t[500005],a[500005],ans[500005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
int p=0;
int l=1;
while(p!=n){
l=1;
for(int i=1+p;i<=n;i++){
    if(cnt[a[i]].v==0){
        t[l]=a[i];
        cnt[a[i]].v++;
        cnt[a[i]].q=l;
        l++;
    }
    else {
        for(int j=cnt[a[i]].q;j<=l;j++){
            cnt[t[j]].v=0;
            cnt[t[j]].q=0;
            t[j]=0;
            l--;
        }
        t[l]=a[i];
        cnt[a[i]].v++;
        cnt[a[i]].q=l;
        l++;
    }
}
for(int i=1;i<=m;i++){
    if(cnt[i].v!=0)ans[i]++;
    cnt[i].v=0;
    cnt[i].q=0;
}
p++;
}
for(int i=1;i<=m;i++){
    cout<<ans[i]<<" ";
}
return 0;
}
