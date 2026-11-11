#include <bits/stdc++.h>
using namespace std;
int a[500005],f[500005],nx[300005],ans[300005],m[300005],c[300005],l[300005];
/*
void unionn(int x)
{
    int t=n[x],t1,t2=f[t];
    f[t]=0;
    while(t2)
    {
        t1=f[t2];
        f[t2]=t;
        t=t2;
        t2=t1;
    }
}
*/
int main()
{
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,t;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[a[i]]++;
        //f[i]=n[a[i]];
        nx[a[i]]=i;
    }
    //for(int i=1;i<=m;i++)unionn(i);
    t=m;
    for(int i=n;i>0;i--)
    {
        if(nx[a[i]]==i)
        {
            l[t--]=a[i];
        }
    }
    for(int i=1;i<=m;i++)
        c[a[nx[l[i]]+1]]+=c[l[i]];//第i个末位数的下一位数继承该末位数值
    for(int i=1;i<=m;i++)
        cout<<c[i]<<' ';
	return 0;
}
