#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long s[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);



    int ans=0;
    for(int i=1; i<=n; i++)//xuanzeshuzi
    {
        memset(s,0,sizeof(s));
        int cnt=1;
        for(int j=1; j<=n; j++)
        {
            s[j]=a[j]-a[i];
        }
        sort(s+1,s+n+1);
        for(int j=1; j<=n; j++)
        {
            if(s[j]>0)break;
            if(m+s[j]>=0)
            {
                cnt++;
                m=m+s[j];
            }

        }
       // cout<<"---"<<i<<" "<<cnt<<endl;
        ans=max(cnt,ans);

    }

    printf("%d",ans);
    return 0;
}

