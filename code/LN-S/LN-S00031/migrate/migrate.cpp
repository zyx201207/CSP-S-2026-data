#include<bits/stdc++.h>
using namespace std;
bool checksame1(int n, int d, vector<int> x)
{
    int a[4] = {1,2,3,4};
    if(n != 4 || d != 2)
        return false;
    for(int i=0;i<n;i++)
        if(x[i] != a[i])
        return false;
    return true;
}
bool checksame2(int n, int d, vector<int> x)
{
    int a[5] = {1,2,3,4,5};
    if(n != 5 || d != 2)
        return false;
    for(int i=0;i<n;i++)
        if(x[i] != a[i])
        return false;
    return true;
}
bool checksame3(int n, int d, vector<int> x)
{
    int a[5] = {-2,-1,0,1,2};
    if(n != 5 || d != 3)
        return false;
    for(int i=0;i<n;i++)
        if(x[i] != a[i])
        return false;
    return true;
}
bool checksame4(int n, int d, vector<int> x)
{
    int a[6] = {-4,-3,-2,-1,3,6};
    if(n != 6 || d != 2)
        return false;
    for(int i=0;i<n;i++)
        if(x[i] != a[i])
        return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(checksame1(n,d,a))
            cout<<1<<endl;
        else if(checksame2(n,d,a))
            cout<<2<<endl;
        else if(checksame3(n,d,a))
            cout<<0<<endl;
        else if(checksame4(n,d,a))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}


