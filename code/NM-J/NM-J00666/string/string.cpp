#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m=0,k=1,a,v=0;
    cin>>n;
    string p,b;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        p+=a*b;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
