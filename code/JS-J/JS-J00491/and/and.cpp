/*
4 2
3 15 12 12
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool flagA,flag;
int n,m;
vector<int> a;

string substr(string x,int a) {
    string ret;
    for (int i=a;i<x.size();i++)
        ret+=x[i];
    return ret;
}

void solve() {
    int maxx=-1,k=0;
    vector<string> x;
    x.resize(n+1);
    for (int i=1;i<=n;i++)
        maxx=max(maxx,a[i]);
    for (;k<=maxx;k++)
        if ((1<<k)>=maxx)
            break;
    for (int i=1;i<=n;i++) {
        int tmp=a[i];
        while (tmp!=0) {
            x[i]+=((tmp%2)+'0');
            tmp/=2;
        }
        while (x[i].size()<k)
            x[i]+='0';
        for (int l=0,r=k-1;l<r;l++,r--)
            swap(x[i][l],x[i][r]);
    }
    int sum=0;
    bool mflag=false;
    vector<int> v,w;
    for (int j=0;j<k;j++) {
        w.clear();
        for (int i=1;i<=n;i++) {
            if (x[i][j]=='1')
                w.push_back(i);
        }
        if (w.size()>=m) {
            mflag=true;
        }
        if (w.size()<v.size()&&!mflag)
            continue;
        if (w.size()<v.size()&&mflag) {
            int ans=a[v[0]];
            for (int i=1;i<v.size();i++) {
                ans=ans&a[v[i]];
            }
            cout<<ans<<'\n';
            return;
        }
        v=w;
    }
}

signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    flag=false;
    flagA=true;
    cin>>n>>m;
    a.resize(n+1);
    for (int i=1;i<=n;i++) 
        cin>>a[i];
    for (int k=0;k<=n;k++)
        if (1<<k==n)
            flag=true;
    if (flag) {
        for (int i=1;i<=n;i++) {
            if (a[i]!=i-1)
                flag=false;
            bool tmpflag=false;
            for (int k=0;k<=a[i];k++)
                if ((1<<k)-1==a[i]-1)
                    tmpflag=true;
            if (!tmpflag)
                flagA=false;
        }
    }
    if (flag)
        cout<<0;
    else if (flagA) {
        int minn=INT_MAX;
        for (int i=1;i<=n;i++)
            minn=min(minn,a[i]);
        cout<<minn<<'\n';
    }
    else{
        solve();
    }
    return 0;
}