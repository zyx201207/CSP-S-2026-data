#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int a[N],b[N];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    b[1]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    if(m>1000000010)
    {
        if(a[1]==a[2]==a[3]==a[4])
        {
            cout<<n;
            return 0;
        }
        else if(a[3]-a[2]==a[2]-a[1]==a[4]-a[3])
        {
          cout<<m/(a[2]-a[1]);
          return 0;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
    }
    int i=1;
    while(b[i]<=m)
    {
        i++;
    }
    printf("%d",i-1);
    fclose(stdin);
    fclose(stdout);
}
