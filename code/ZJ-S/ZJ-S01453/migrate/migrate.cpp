#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

void solve(){
    int n;
    ll d;
    cin>>n>>d;
    vector<ll> x(n);
    for(int i=0;i<n;i++)cin>>x[i];
    vector<int> nxt(n),pre(n);
    for(int i=0,j=0;i<n;i++){
        j=max(j,i);
        while(j+1<n&&x[j+1]-x[i]<=d)j++;
        nxt[i]=j;
    }
    for(int i=n-1,j=n-1;~i;i--){
        j=min(j,i);
        while(j&&x[i]-x[j-1]<=d)j--;
        pre[i]=j;
    }
    vector<int> f1(n),f2(n),f3(n);
    for(int i=0;i<n;i++){
        f1[i]=pre[nxt[i]]==i;
        f2[i]=pre[nxt[i]]==i-1&&pre[i-1]==pre[i];
        f3[i]=pre[nxt[i]]==i-1;
    }
    vector<int> w1(n),w2(n),w3(n);
    for(int x=n-1,p=n-1;~x;x--)if(x<nxt[x]){
        const int y=nxt[x];
        p=min(p,y);
        while(p>x&&pre[p]>=x)p--;
        const int q=p;
        while(p>x&&pre[p]==x-1)p--;
        w1[x]=q-p;
    }
    for(int x=n-1,p=n-1;~x;x--)if(x<nxt[x]){
        const int y=nxt[x];
        p=min(p,y);
        while(p>x&&pre[p]>x)p--;
        const int q=p;
        while(p>x&&pre[p]==x)p--;
        w2[x]=q-p;
    }
    for(int x=n-1,p=n-1;x;x--)if(x<nxt[x]&&pre[x]==pre[x-1]){
        const int y=nxt[x];
        p=min(p,y);
        while(p>x&&pre[p]>=x)p--;
        const int q=p;
        while(p>x&&pre[p]==x-1)p--;
        w3[x]=q-p;
    }
    vector<int> dep(n);
    vector<ll> s2(n+1),s3(n+1);
    for(int i=n-1;~i;i--){
        if(i<nxt[i])dep[i]=dep[nxt[i]]+1;
        s2[i]=s2[nxt[i]]+(i<nxt[i]?w2[nxt[i]]:0);
        s3[i]=s3[nxt[i]]+(i<nxt[i]?w3[nxt[i]]:0);
    }
    vector<int> nf1(n,n);
    for(int i=n-1;~i;i--)if(i<nxt[i]){
        if(!f1[i])nf1[i]=i;
        else nf1[i]=nf1[nxt[i]];
    }
    ll ans=0;
    for(int u=0;u<n;u++)if(dep[u]>=2){
        ans+=w1[nxt[u]];
        int x=nxt[u];
        int y=nf1[x];
        ans+=s3[x]-s3[y];
        if(y==n||!(y==x?f3[y]:f2[y]))continue;
        int z=nf1[nxt[y]];
        ans+=s2[y]-s2[z];
    }
    cout<<ans<<endl;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int _,T;
    cin>>_>>T;
    while(T--)solve();
    return 0;
}