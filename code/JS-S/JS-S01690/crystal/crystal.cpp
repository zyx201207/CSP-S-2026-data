// ++rp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5+5;
const int mod = 1e9+7;
const int inf = INT_MAX;

int n,m,a[N],b[N],mx,mi,c[N],d[2*N];
bool s=1;
// who can give me some marks
// coming, loving, getting less than 45+30 marks, leaving;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);// freopen("crystal.in","w",stdout);
    freopen("crystal.out","w",stdout);// freopen("crystal.ans","w",stdout);
    cin>>n>>m;
    int ls=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    int ans=0;
    sort(a+1,a+n+1);
    
    for(int i=1;i<=n;i++) {
        d[N+a[i]]++;
        if(i==2) {
            ls=a[i]-a[i-1];
        }
        if(i>2) {
            if(ls!=a[i]-a[i-1]) s=0;
        }
    }
    n=unique(a+1,a+n+1)-a;
    n--;
    if(n<=5e4) {
        ans=1;
        for(int i=n;i>=1;i--) {
            int l=m,bs=i,an=d[N+a[i]];
            while(l>0&&bs>0) {
                bs--;
                l-=(a[i]-a[bs])*d[N+a[bs]];
                an+=d[N+a[bs]];
                // cout<<l<<" "<<an<<" "<<bs<<" "<<a[bs]<<" "<<d[N+a[bs]]<<"\n";
                if(l==0) {
                    ans=max(ans,an);
                } else if(l<0) {
                    l+=(a[i]-a[bs])*d[N+a[bs]];
                    an-=d[N+a[bs]];
                    an+=l/(a[i]-a[bs]);
                    l=l%(a[i]-a[bs]);
                    ans=max(ans,an);
                }
            }
            ans=max(ans,an);
            // cout<<l<<" "<<bs<<" "<<ans<<"\n\n";
        }
        cout<<ans;
    } else if(s) {
        for(int i=1;i<=n;i++) {
            if(i*(i-1)*ls>2*m) {
                cout<<i-1;
                return 0;
            } 
        }
    }
    return 0;
}

/*
10 3
2 4 6 8 10
*/