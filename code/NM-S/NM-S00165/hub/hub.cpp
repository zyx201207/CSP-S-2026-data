#include<bits/stdc++.h>
using namespace std;
long long u[100000010],v[100000010];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=0,t=0;
    cin>>c>>t;
    while(t)
    {
        int n=0,k=0;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            cin>>u[i]>>v[i];
        }
        t--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
