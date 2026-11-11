#include<bits/stdc++.h>
using namespace std;

long long a[2000005];
int l[2000005],id[2000005],sl[2000005],sr[2000005],t;
void add(int ql,int qr) {
    if(id[ql]==t&&t!=0) {
        l[qr]=l[ql];
        id[qr]=t;
        l[ql]=0;
        id[ql]=0;
    } else {
        t++;
        l[qr]=ql;
        id[qr]=t;
    }
}
void work() {
    t=0;
    int n;
    long long d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        l[i]=0;
        sl[i]=0;
        sr[i]=0;
        id[i]=0;
    }
    int p=1;
    bool b;
    for(int i=1;i<=n;i++) {
        p=max(p,i);
        b=0;
        while(p<n&&a[p+1]-a[i]<=d) {
            p++;
            b=1;
        }
        if(b) add(i,p);
    }
    int ll=n;
    for(int i=n;i>=1;i--) {
        if(l[i]==0) continue;
        sl[i]=ll-l[i];
        ll=l[i];
    }
    for(int i=1;i<=n;i++) {
        if(l[i]==0) continue;
        if(l[i-1]==0) sl[i]+=sl[l[i]];
    }
    int rr=1;
    for(int i=1;i<=n;i++) {
        if(l[i]==0) continue;
        sr[i]=i-rr;
        rr=i;
    }
    for(int i=n;i>=1;i--) {
        if(l[i]==0||l[l[i]]==0) continue;
        if(l[i-1]!=l[i]-1) sr[l[i]]+=sr[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(l[i]==0||i-l[i]==1) continue;
        // cout<<l[i]<<' '<<i<<"\n";
        if(l[l[i]+1]!=0) {
            p=l[i]+1;
            // cout<<sr[i]<<' '<<sl[p]<<"\n";
            if(p-l[i]==1) ans+=1ll*sr[i]*sl[p];
        }
    }
    cout<<ans<<"\n";
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--) work();
    return 0;
}