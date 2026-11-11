#include<bits/stdc++.h>
using namespace std;

int b[200001][30];
bool flag[200001];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int a,j=0;
        cin>>a;
        while(a!=0)
        {
            b[i][j]=a%2;
            a/=2;
            j++;
        }
    }
    int ans=0;
    for(int j=29;j>=0;j--)
    {
        int s=0;
        for(int i=0;i<n;i++)
        {
            if(b[i][j]&&!flag[i])
            {
                s++;
            }
        }
        if(s>=m)
        {
            ans+=(1<<j);
            for(int i=0;i<n;i++)
            {
                if(!b[i][j])
                {
                    flag[i]=1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
