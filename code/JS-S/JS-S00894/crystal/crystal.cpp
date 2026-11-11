#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);

long long n,m;
cin >> n>> m;
for(int i=1;i<=n;i++)
{
    cin >> a[i];
}
sort(a+1,a+n+1);
long long ansn=0;
for(int w=1;w<=n;w++)
{

    long long i=a[w];
    long long ans=0,cnt=0;
    for(int j=1;j<=n;j++)
    {
        if(a[j]<=i)
        {
            ans+=i-a[j];
            cnt++;
        }

    }
    if(ans<=m)
    {

        ansn=max(ansn,cnt);
    }
    else{
            for(int j=1;j<=n;j++)
    {
        if(a[j]<=i)
        {
            ans-=i-a[j];
            cnt--;
              if(ans<=m)
    {

        ansn=max(ansn,cnt);
    }

        }

    }
    }
}




cout << ansn;
return 0;
}
