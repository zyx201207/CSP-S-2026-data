#include <bits/stdc++.h>
#define fo(i,j,k) for(int i=j;i<=k;i++)
#define go(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=500017;
ll n,m,a[N];
ll l,r,sum,maxx=-1e18,num,ans;
void add(int x){
    if(x>maxx){
        sum+=num*(x-maxx);
        maxx=x;
    }
    else sum+=maxx-x;
    num++;
}
void del(int x){
    sum-=maxx-x;
    num--;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    fo(i,1,n){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    while(r<n){
        add(a[++r]);
        while(sum>m){
            del(a[++l]);
        }
        ans=max(ans,num);
    }
    printf("%lld\n",ans);
    return 0;
}
