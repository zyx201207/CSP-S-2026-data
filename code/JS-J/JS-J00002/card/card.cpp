#include <bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=3e5+9;
#define ll long long
ll n,m;
ll s[N],f[N],a[N],df[N],st[N];
void solve(int nm){
    ll top=1;
    memset(df,0,sizeof(df));
    memset(f,0,sizeof(f));
    memset(st,0,sizeof(st));
    for(int i=nm;i<=n;i++){
        if(df[a[i]]==0){
            f[top]=a[i];
            df[a[i]]=1;
            st[a[i]]=i;
            top++;
        }
        else{
            df[a[i]]=0;
            for(int j=st[a[i]];j<i;j++){
                f[j]=0;
                df[a[j]]=0;
            }
            f[i]=a[i];
            df[a[i]]=1;
            st[a[i]]=i;
            top=1;
        }
    }
    for(int i=1;i<=m;i++){
        s[i]+=df[i];
    }
    return;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    for(int i=1;i<=n;i++){
           solve(i);
    }
    for(int i=1;i<=m;i++)cout<<s[i]<<" ";
    return 0;
}
