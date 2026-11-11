#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,flag=1,num,f[200005],maxx[200005];
string x,y;
bool cmp(long long int x,long long int y)
{
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>f[i];
    }
    sort(f,f+n,cmp);
    while(f[0]!=0)
    {
        if(f[0]%2==1)
            x.push_back('1');
        else
            x.push_back('0');
        f[0]/=2;
    }
    while(f[m-1]!=0)
    {
        if(f[m-1]%2==1)
            y+='1';
        else
            y+='0';
        f[m-1]/=2;
    }
    int len=min(x.length(),y.length());
    for(i=0;i<len;i++)
    {
        if(x[i]==y[i])
        {
            num+=flag;
            flag*=2;
        }
        else
            flag*=2;
    }
    cout<<num;
    return 0;
}
