#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int a[N],s[M],lst[M],nxt[N],mp[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++)mp[j]=0;
        for(int j=0;j<=n;j++)nxt[j]=0;
        for(int j=0;j<=m;j++)lst[j]=0;
        for(int j=i;j<=n;j++){
            nxt[lst[a[j]]]=j;
            lst[a[j]]=j;
        }
        for(int j=i;j<=n;j++){
            if(nxt[j])j=nxt[j]-1;
            else if(!mp[a[j]])s[a[j]]++,mp[a[j]]=1;
        }
    }
    for(int i=1;i<=m;i++)cout<<s[i]<<' ';
    return 0;
}
