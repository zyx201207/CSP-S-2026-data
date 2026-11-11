#include <bits/stdc++.h>
using namespace std;

int a[200005], c[200005];
int f(int m)
{
    int sum=c[0];
    for(int i=1; i<m; i++)
        sum = sum&c[i];
    return sum;
}
long long choose(int start, int end, int n, int m)
{
    if(n==0) return f(m);
    int num=0;
    for(int i=start; i<=end-n; i++)
    {
        c[m-n]=a[i];
        int o = choose(i+1, end, n-1, m);
        if(o>num) num = o;
    }
    return num;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++)
    {
        cin >> a[i];
    }
    cout << choose(0, n, m, m);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
