#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
    return a<b;
}
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    long long a[n+1]={0};
    int cha;
    bool flag = true;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (i==2) cha = a[i]-a[i-1];
        else if (i>2&&cha!=a[i]-a[i-1]) flag = false;
    }
    sort(a,a+n+1,cmp);
    if (flag&&n>=5000){
        long long temp = a[2]-a[1];
        long long ans = floor(sqrt(0.25+1.0*m/temp*2))+0.5;
        cout << ans+1;
    }else {
    long long sum[n+1]={0};
    for (int i=1;i<=n;i++){
        if (i==1) sum[i]=a[i];
        else sum[i]=sum[i-1]+a[i];
    }
        long long maxn=1;
        for (int i=1;i<=n;i++){
            if (i*a[i]-sum[i]<=m){
                maxn = i;
            }else break;
        }
        cout << maxn;

    }

    return 0;
}
