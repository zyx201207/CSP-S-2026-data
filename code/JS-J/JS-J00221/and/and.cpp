#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int yuyu=-1;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    if(m==2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i]==a[j])
                {
                    continue;
                }

                else
                {
                    yuyu=max(yuyu,a[i]&a[j]);
                }
            }
        }
        cout<<yuyu<<endl;
    }
    return 0;
}
