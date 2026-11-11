#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n1,n2[20005]={0},m,a;
    cin>>n2[20005],m;
    for(int i=1;i<=n1;i++)
    {
        cin>>n2[i];
    }
    for(int i=1;i<=m;i++)
    {
        a=n2[i] and n2[i+1];
    }
    cout<<a;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
