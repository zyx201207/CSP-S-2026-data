#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+7;
int n,ans;ll m,a[N],s[N];
bool check(int i,int x){
    return a[i]*x-s[i]+s[i-x] <= m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) s[i] = s[i-1]+a[i];
    for(int i = 1;i <= n;i++){
        int l = 1,r = i;
        while(l < r){
            int mid = (l+r+1)>>1;
            if(check(i,mid)) l = mid;
            else r = mid-1;
        }
        ans = max(ans,l);
    }
    printf("%d\n",ans);
    return 0;
}
