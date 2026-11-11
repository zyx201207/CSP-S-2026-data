#include <bits/stdc++.h>
using namespace std;
int n;
int vis=1,vis2=1;
struct node{
    int x;
    char c;
}a[200005];

void solve1() {cout<<0;}
void solve2()
{
    if (a[1].c==a[2].c) cout<<0;
    else
    {
        if ((a[1].x+a[2].x)%2==0) cout<<min(a[1].x,a[2].x);
        else if (a[1].x==a[2].x){cout<<a[1].x;}
        else cout<<min(a[1].x,a[2].x);
    }
}

void solve3()
{
    int ans=0;
    string s="";
    for (int i=1;i<=n;i++) s+=a[i].c;
    for (int i=1;i<=n/2;i++) if (s[i]!=s[n-i+1]) ans++;
    cout<<ans;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].c;
    for (int i=1;i<=n;i++) if (a[i].x!=1) vis=0;
    for (int j=2;j<=n;j++) if (a[j].c!=a[j-1].c) vis2=0;
    if (vis2==1) {cout<<0;return 0;}
    if (n==1) solve1();
    else if (n==2) solve2();
    else if (vis==1) solve3();
    return 0;
}
