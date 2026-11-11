#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int w;
    long long m;
    cin>>n>>m;
    int a[500001];
    int ans=0;
    int q=n/2+1;
    for(int i=1;i<n;)
    {
        cin>>a[i];

        if(a[i]>=0)
            w=a[q]-a[i];
        if(a[i]<0)
            {
                int o=abs(a[i]);
                w=a[q]+o;
            }

        if(m>0 and w<=m)
        {
            m-=w;
            ans+=1;
            i++;
            w=0;

        }


    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);

}
