#include <bits/stdc++.h>

using namespace std;
long long n,m;
int a[500010];
long long sum=0;
long long k=0;
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

   for(int i=0;i<m;i++)
    {
        sort(a,a+n,cmp);
        if(i==0&&a[i]<a[i+1]&&k!=m)
        {
            a[i]+=a[i];
            k++;
            continue;
        }
        if(i==0&&a[i]==a[i+1]&&k!=m)
        {
            a[i]+=a[i];
            k++;
            a[i+1]+=a[i+1];
            k++;
            continue;
        }
        if(i!=0&&a[i-1]==a[i]&&a[i]<a[i+1]&&k!=m)
        {
            a[i]+=a[i];
            k++;
            if(i!=0&&k!=m)
            {
                for(int j=i;j>=0;j--)
                {
                    a[j-1]+=a[j-1];
                    k++;
                    if(a[j-1]==a[j]&&i==0&&k!=m)
                    {
                        continue;
                    }
                }
            }
        }
        if(k==m)
        {
            for(int j=i;j>=0;j--)
            {
                a[j]==0;
                sum++;

            }
            break;
        }
    }
    cout<<sum;
    return 0;
}
