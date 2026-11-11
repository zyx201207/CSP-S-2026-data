#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
int n;
long long m;
int a[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        int ji=a[i]*i;
        if(ji-m==sum)
        {
            int cnt=0;
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]==a[i])
                    cnt++;
            }
            cout<<cnt+i;
            break;
        }
    }
    return 0;
}
