#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    long long n,m,a[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
