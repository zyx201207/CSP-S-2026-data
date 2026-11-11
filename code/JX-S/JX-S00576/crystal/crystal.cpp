#include<bits/stdc++.h>
using namespace std;
int a[100000]={};
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    long long n=0,m=0,ci=0;
    cin>>n>>m;
    ci=m;
    for(int i=1;i<=n;i++)
    {
        //scanf("%l",a[i]);
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int j=1;
    while(ci>0)
    {
        for(int i=j;i>0;i--)
        {
            for(int w=0;w<=a[j+1]-a[i];w++)
            {
                if(ci>0) ci--;
                else break;
                a[i]++;
                //cout<<i<<" "<<j<<" "<<a[i]<<endl;
            }
        }
        if(a[j]==a[j+1]) j++;
    }
    j=1;

    int ans=1;
    /*
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    */
    while(true)
    {
       if(a[j]==a[j+1])
       {
           ans++;
           j++;
       }else
       {
            break;
       }
    }
    cout<<ans;
    return 0;
}
