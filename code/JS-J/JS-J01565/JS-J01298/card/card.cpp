#include<bits/stdc++.h>
using namespace std;

int a[500005],n,m,ans[300005];
void emy(int x){
    int mem[300005];
    memset(mem,0,sizeof mem);
    for(int i=x;i<=n;i++){
        if(mem[a[i]]!=0){
            for(int j=mem[a[i]];j<=i-1;j++)mem[a[j]]=0;
        }
        mem[a[i]]=i;
    }

    for(int i=x;i<=n;i++){
        if(mem[a[i]]!=0){
            ans[a[i]]++;
            mem[a[i]]=0;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        emy(i);
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
