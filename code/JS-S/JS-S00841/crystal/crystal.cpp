#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
typedef long long LL;
int n;
LL a[N];
LL m;
bool check(int mid)
{
    LL res = 0; 
    for(int i = 1;i<mid;i++) res += a[i];
    for(int i = mid;i<= n;i++)
    {
        res += a[i];
        if(a[i] * mid -res <= m)return false;
        res-= a[i-mid + 1];
    }
    return true;
}
int  search()
{
    int l = 1,r = n;
    int mid ;
    while(l<= r)
    {
        mid = (l + r)>> 1;
        if(!check(mid)) l = mid + 1;
        else r = mid-1;
    }
    return r;

}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i<= n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    cout<<search();
    return 0;
}