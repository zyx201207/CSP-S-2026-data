#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll INF=1e12+10;
int n;
ll m,a[N];
ll pre[N];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        pre[i]=pre[i-1]+a[i];
    }
    sort(a+1,a+n+1);
    if(n*a[n]-pre[n]<=m){
        printf("%d",n);
        return 0;
    }
    for(int st=1;st<=n;st++){
        int l=st,r=n;
        while(l<=r){
            int mid=l+r>>1;
            if((mid-st+1)*a[mid]+pre[st-1]-pre[mid]>m){
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,l-st);
    }
    printf("%d",ans);
    return 0;
}
