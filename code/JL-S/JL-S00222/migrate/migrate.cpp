#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a,b;
    while(m--)
    {
        cin>>a>>b;
        cout<<a/(b+1)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
