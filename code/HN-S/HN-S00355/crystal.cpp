#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define ro(i,r,l) for(int i=r;i>=l;i--)
const int N=5e5+5;
int n,m,a[N],pre[N],rs;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    fo(i,1,n)
        cin>>a[i];
    sort(a+1,a+n+1);
    fo(i,1,n)
        pre[i]=pre[i-1]+a[i];
    fo(i,1,n){
        int x=a[i],l=1,r=i;
        while (l<r){
            int mid=(l+r)>>1;
            if (x*(i-mid+1)-(pre[i]-pre[mid-1])<=m)
                r=mid;
            else l=mid+1;
        }
        rs=max(rs,i-l+1);
    }
    cout<<rs<<'\n';
    return 0;
}