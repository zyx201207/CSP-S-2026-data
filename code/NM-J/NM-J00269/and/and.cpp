#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<long long> b;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        long long k=0;
        cin>>k;
        a.push_back(k);
    }
    sort(a.rbegin(),a.rend());
    for(int i=0;i<m;i++)
    {
        b.push_back(a[i]);
    }
    long long mx=0;
    mx=b[0];
    for(int i=1;i<m;i++)
    {
        mx&=b[i];
    }
    cout<<mx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
