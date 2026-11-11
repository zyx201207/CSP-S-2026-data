#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//scanf("%lld%lld",&a,&b);
//printf("%lld",a*b);

const ll N = 1e6+5;

vector<int> mapa[N];
ll n,m;
ll a[N];
ll cha[N];
ll dp[50005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }

    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
    for(int i=1;i<n;i++){
        cha[i] = a[i+1]-a[i];
    }
    int maxn = 0;
    for(int i=1;i<n;i++){
        int sum=0;
        int j_1;
        for(int j=1;i+j<=n;j++){
            sum = sum+cha[i+j-1]*j;
            if(sum>m){
                j_1 = j;
                break;
            }
        }
        int j = j_1;
        maxn = max(maxn,(j==1)?0:j);
    }
    cout<<maxn;
    return 0;
}
