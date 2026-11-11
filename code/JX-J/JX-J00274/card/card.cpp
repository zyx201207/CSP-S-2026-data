#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],b[N],t[N],ans[N];

int main(){
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;++i)cin>>a[i];
for(int i=1;i<=n;++i){
    for(int j=i;j<=n;++j){
        if(t[j]==0){
            b[j]=a[j];
        }
        else{
            for(int k=j;k>=i;k--){
                if(b[k]==b[j]){
                    b[k]=0;
                    break;
                }
                b[k]=0;
            }
    }
    for(int j=1;j<=n;++j){
        ans[b[j]]++;
        t[j]=0;
    }
}
}
for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
return 0;
}
