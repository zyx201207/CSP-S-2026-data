#include <bits/stdc++.h>
using namespace std;
int n;
long long m,b[100001],c[100001],a[100001],sum = 1,ans = 1e18;
int main(){
    freopen("crystal.cpp","r",stdin);
    freopen("crystal.cpp","r",stdout);
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i++){
        c[i] = 1e18;
        b[i] = c[i];
    }
    long long x = (a[1] + a[n]) / 2;
    int r = 0;
    for(int i = 1;i <= n;i++)
        if(abs(a[i] - x) <= ans) r = i,ans = abs(a[i] - x);
    int g = 0,h = 0;
    for(int i = 1;i < r;i++)
        b[++g] = abs(a[r] - a[i]);
    for(int j = r + 1;j <= n;j++)
         c[++h] = abs(a[j] - a[r]);
    int j = 1;
    while(g >= 1 && m >= min(c[j],b[g]))
    while(j <= h && m >= min(c[j],b[g])){
        if(b[g] < c[j] && m >= b[g]) m -= b[g],sum++,g--;
        else if(b[g] >= c[j] && m >= c[j]) m -= c[j],sum++,j++;
    }
    while(g != 0 && m >= b[g])
         sum++,m -= b[g],g--;
    while(j <= h && m >= c[j])
          sum++,m -= c[j],j++;
    printf("%lld",sum);
}
