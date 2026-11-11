#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a;
    int cmp[100001];
    int cnt[100001];
    int result[100001];
    int p[100001];
    int biggest=0;
    int t=0,q=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        cmp[i]=a%2;
    }
    for(int i=n; i>=1; i--)
    {
        cnt[i]=cmp[i];
        result[i]=(cmp[i]&&cnt[i]);
    }
    for(int i=n; i>=1; i--)
    {
        p[i]=result[i];
    }
    for(int i=1; i<=n; i++)
    {
          t=p[n]-p[i];
          for(int i=1;i<=n;i++){
            q=p[i]*(p[n]-p[i])*2;
          }
    }
    cout<<q;
    return 0;
}
