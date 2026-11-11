#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool check(int x,int y)
{
    for(int i = 1;i <= x;i++)
    {
        y -= a[x]-a[i];
    }
    if(y >= 0) return true;
    else return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int lb = 1,rb = n;
    while(lb < rb)
    {                                                                                                      
        if(rb - lb == 1) break;
        int mid = (lb+rb)/2;
        if(check(mid,m))
        {
            lb = mid;
        }
        else
        {
            rb = mid-1;
        }
    }
    cout << lb;
    return 0;
}