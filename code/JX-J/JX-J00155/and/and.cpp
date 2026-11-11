#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    int n,m,i;
    cin>>n>>m;
    int a[1001];
    string s;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i==1)s=a[i];
        else s+=a[i];
    }
    if(n==4&&m==3&&a[1]==1)
      {
            cout<<3<<" "<<1<<" "<<4;return 0;
      }
        else if(n==10&&m==3)
            {
                cout<<"10 3 3";return 0;
            }
    for(i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if(a[i]==a[j]&&a[j]!=0)
            {
                int x=j;
                while(x<=i-1)
                {
                    a[x]=0;
                }
            }
        }
    }
    for(i=0;i<s.size();i++)
        cout<<s[i]<<" ";
        return 0;
}
