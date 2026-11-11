#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

// #define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) void()

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
    ll ans=0;
    for(int u=0;u<n;u++){
        debug("u = %d\n",u);
        vector<int> pth;
        pth.push_back(u);
        while(nxt[pth.back()]!=pth.back())pth.push_back(nxt[pth.back()]);
        for(int i:pth)debug("%d ",i);debug("\n");
        if(pth.size()>=3){
            int p=pth[2];
            while(p>pth[1]&&pre[p]==pth[1])p--;
            int q=p;
            while(q>pth[1]&&pre[q]==pth[1]-1)q--;
            ans+=p-q;
            debug("type0: p = %d, q = %d, ans = %lld\n",p,q,ans);
        }
        int p=1,cnt=0;
        while(p+2<pth.size()&&f1[pth[p]]){
            int z=pth[p+2];
            while(z>pth[p+1]&&pre[z]==pth[p+1])z--;
            int zz=z;
            while(zz>pth[p+1]&&(pre[zz]==pth[p+1]-1&&pre[pth[p+1]]==pre[pth[p+1]-1]))zz--;
            ans+=z-zz;
            debug("type1: p = %d, z = %d, ans = %lld\n",p,z,ans);
            p++;
        }
        while(p+2<pth.size()){
            if(f1[pth[p]]);
            else if(p==1?f3[pth[p]]:f2[pth[p]])cnt++;
            else break;
            if(cnt>1)break;
            int z=pth[p+2];
            while(z>pth[p+1]&&pre[z]==pth[p+1])z--;
            ans+=pth[p+2]-z;
            debug("type2: p = %d, z = %d, ans = %lld\n",p,z,ans);
            p++;
        }
        debug("u = %d, ans = %lld\n",u,ans);
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