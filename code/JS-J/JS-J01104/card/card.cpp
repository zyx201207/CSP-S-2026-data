#include <bits/stdc++.h>
using namespace std;
int f[500005],l[500005],r[500005],s[500005],p[500005],ans[500005];
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for (int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    memset(f,-1,sizeof f);
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    memset(s,0,sizeof s);
    memset(p,0,sizeof p);
    for (int i=0;i<n;i++){
        if (f[a[i]]==-1){
            f[a[i]]=i;
        }
        r[a[i]]=i;
        s[a[i]]++;
    }
    for (int i=0;i<n;i++){
        l[r[a[i]]]=a[i];
    }
    for (int i=1;i<=m;i++){
        ans[i]=s[i];
    }
    for (int i=1;i<n;i++){
        if (l[i-1]>0){
            p[i]+=ans[l[i-1]];
        }
        ans[a[i]]+=p[i];
    }
    for (int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
