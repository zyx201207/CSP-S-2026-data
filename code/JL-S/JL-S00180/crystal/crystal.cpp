#include<bits/stdc++.h>
using namespace std;
int a[100000001];
int n,m,sum=0,av,av2;
bool cmp(int a,int b)
{
    return sqrt(pow(a-av2,2))<sqrt(pow(b-av2,2));
}
int main()
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
        sum+=a[i];
    }
    av=sum/n;
    int mi=0x7f7f7f7f;
    av2=av;
    for(int i=av-sqrt(sum);i<=av+sqrt(sum);i++)
    {
        int num=0;
        for(int j=0;j<=n;j++)
        {
            num+=abs(i-a[j]);
        }
        if(num<mi)
        {
            mi=num;
            av2=i;
        }
    }
    sort(a,a+n,cmp);
    int i=1;
    while(i++)
    {
        if(m-abs(a[i]-av2)<0)
        {
            cout<<i;
            break;
        }
        else if(m-abs(a[i]-av2)==0)
        {
            cout<<i;
            break;
        }
        else
        {
            m-=abs(a[i]-av2);
        }
    }
    return 0;
}
