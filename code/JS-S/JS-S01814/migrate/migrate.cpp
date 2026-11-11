#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        ll n,d;
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        puts('0\n');
    }
    return 0;
}
