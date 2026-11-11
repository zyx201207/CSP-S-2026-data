#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 * 5;
long long n,m,a[N],ans = -1e8,sum;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    long long mx,p;
    for(int i=1;i<=n;i++){
        mx = INT_MIN,p = 0;
        for(int j=1;j<=n;j++){
            sum = 0;
            for(int k=i;k<=j;k++){
                if(a[k] > mx){
                    mx = a[k];
                    p = k;
                }
            }
            for(int k=i;k<=j;k++){
                if(k == p) continue;
                sum += (mx - a[k]);
            }
            if(sum > m){
                cout<<j - 1;
                return 0;
            }
        }
    }
    return 0;
}
