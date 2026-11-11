#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cnt;
int a[300010][32];
vector<long long> b;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    b.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        int k=1,j;
        int t=b[i];
        for(j=0;k<=t;j++)
        {
            k*=2;
        }
        for(;t>0;)
        {
            k/=2;
            if(t>=k)
            {
                a[i][32-j]=1;
                t-=k;
            }
            j--;
        }
    }
    int z=m;
    for(int j=1;j<=32&&z;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cnt+=a[i][j];
        }
        if(cnt>=m&&z)
        {
            ans+=1<<(31-j);
            z--;
        }
        cnt=0;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
