#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool cmp(int a,int s){
    return a>s;
}
void dfs(int id,int k,int x){
    if(k==m){
        ans=max(ans,x);
        return;
    }
    if(n-id+1<m-k)return;
    ++id;
    if(k==0){
        dfs(id,0,0);
        dfs(id,1,a[id-1]);
        return;
    }
    dfs(id,k,x);
    dfs(id,k+1,(x&a[id-1]));
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int x=0;
    for(int i=1;i<=n;i++)x=max(x,a[i]);
    if(n<=20||m==1||m==2||m==n||m==n-1){
        dfs(1,0,0);
        cout<<ans;
        return 0;
    }
    if(x<4){
        int t[]={0,0,0,0};
        for(int i=1;i<=n;i++)t[a[i]]++;
        if(m<=t[3])cout<<3;
        else if(m<=t[3]+t[2])cout<<2;
        else if(m<=t[3]+t[1])cout<<1;
        else cout<<0;
        return 0;
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[m];
    return 0;
}
