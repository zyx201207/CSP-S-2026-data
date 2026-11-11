#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+5;
const int INF=0x3f3f3f3f;
long long n,m,sum;
int ans=-INF,l,r;
int a[MAXN],cf[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)
        cf[i-1]=a[i]-a[i-1];
    l=r=1;
    while(l<n){
        if(sum>m||r>=n){
            l++;
            sum-=a[r]-a[l-1];
            continue;
        }
        ans=max(ans,r-l+1);
        r++;
        sum+=(r-l)*cf[r-1];
    }
    cout<<ans<<'\n';
    return 0;
}