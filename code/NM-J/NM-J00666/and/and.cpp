#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m,a,s=0;
    cin>>n>>m;
    s=a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>=s)
        {
            s=a;
        }
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
