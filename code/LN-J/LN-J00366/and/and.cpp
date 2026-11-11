#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1000;
int a[200005];
void digui(int cnt,int c,int i)
{
    if((c>m)||(i==n))
    {
        return;
    }
    else
    {
        for(int k=i;k<n;k++)
        {
            int sum=cnt&a[k];
            if(sum>ans&&(c==m))
            {
                ans=sum;
            }
            digui(sum,c+1,k+1);
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        digui(a[i],2,i+1);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
