#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll m;
int n;
ll a[500010];
ll pre[500010];
ll dist1[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        dist1[i] = a[i]-a[1];
    }
    for(int i = 1;i <= n;i++){
        pre[i] = dist1[i]+pre[i-1];
    }
    int i = 1;
    int len = 1;
    int cnt = 1;
    for(int j = 2;j <= n;j++){
        if((j-i)*(dist1[j]-dist1[i])-(pre[j-1]-pre[i]-(j-1-i)*dist1[i]) <= m){
            len++;
        }
        else{
            i++;
        }
    }
    cout << len;
    return 0;
}
