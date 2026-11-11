#include<bits/stdc++.h>
using namespace std;
int n,m,maxxx;
int a[200010];
int b[40010][10010];
int f(int i,int deepth,int ansnow,int maxx)
{
    ansnow&=a[i];
    if(deepth==m)
        return ansnow;
    if(b[i][deepth]==0)
    {
        for(int j=i+1;j<n;j++)maxx=max(maxx,f(j,deepth+1,ansnow,maxx));
        b[i][deepth]=maxx+1;
    }
    return b[i][deepth]-1;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%d",a[i]);
    for(int i=0;i<n;i++)maxxx=max(maxxx,f(i,1,a[i],-1));
    cout<<maxxx;
    return 0;
}
