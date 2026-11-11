#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int n,d;
int a[N],s[N];
int g1[N],g2[N];
int get(int x){
    int l=x-1,r=n+1;
    while(l+1<r){
        int md=(l+r)/2;
        if(s[md]-s[x]<=d)l=md;
        else r=md;
    }
    return l;
}
int rget(int x){
    int l=0,r=x+1;
    while(l+1<r){
        int md=(l+r)/2;
        if(s[x]-s[md]<=d)r=md;
        else l=md;
    }
    return r;
}
bool ck(int l,int r){
    int now=l,k=0,ls=-1,t=0;
    while(get(now)<=r){
        t++;
        ls=now;
        now=get(now);
        if(ls==now&&now<r)return 0;
    }
    if(now!=r&&get(now)==r){
        t++;
        now=r;
    }
    if(now!=r&&get(now)<r){
        return 0;
    }
    cout<<l<<' '<<r<<" "<<t<<"\n";
    vector<int>g;
    for(int i=l;i<=r;i++){
        if(i-l+1<=t)g.push_back(1);
        else g.push_back(0);
    }
    sort(g.begin(),g.end());
    int res=0;
    while(next_permutation(g.begin(),g.end())){
        vector<int>v;
        for(int i=0;i<g.size();i++){
            if(g[i]==1){
                v.push_back(l+i);
            }
        }
        for(int i=1;i<v.size();i++){
            if(get(v[i-1])<v[i])goto as;
        }
        res++;
        as:;
    }
    if(res==2)return 1;
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--){
        bool f=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i]=a[i]-a[i-1];
        }
        for(int i=3;i<=n;i++){
            if(s[i]!=s[i-1])f=0;
        }
        if(f==0){
            int ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+3;j<=n;j++){
                    if(ck(i,j))ans++;
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        s[1]=0;
        for(int i=2;i<=n;i++){
            s[i]+=s[i-1];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            g1[i]=get(i);
            g2[i]=rget(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(g1[i]-1==g2[j])ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
