#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 5e5+10;

int n,m;
int a[N];
int c[N];
int ans = 0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++){
        c[i] = c[i-1]+a[i];
    }
    int l = 1;
    for (int i = 1;i <= n;i++){
        while (!((i-l)*a[i]-c[i-1]+c[l-1] <= m)){
            l++;
        }
        ans = max(ans,i-l+1);
    }
    printf("%lld",ans);



    return 0;
}