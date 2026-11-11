#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,m,a[500005],sum[5000005],top;
map<int,int>num;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!num.count(a[i]))
        {
            top++;
            num[top]=a[i];
        }
    }
    for(int i=2;i<top;i++)
        for(int j=1;j<i;j++)
            if(num[j]>num[j+1])swap(num[j],num[j+1]);
    for(int i=1;i<=m;i++)
    {
        map<int,int>bj;
        for(int j=i;j<=n;j++)
        {
            if(bj.count(a[j]))
            {
                for(int k=bj[a[j]];k<=j;k++)
                {
                    bj[a[k]]=-10086;
                }
                bj[a[j]]=114514;
            }
            bj[a[j]]=j;
        }
        for(int k=1;k<=top;k++)
            if(bj.count(num[k]))sum[k]++;
    }
    for(int i=1;i<=top;i++)
    {
        if(i!=1)cout<<" ";
        cout<<sum[i];
    }
	return 0;
}
