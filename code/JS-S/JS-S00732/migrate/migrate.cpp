#include<cstdio>
#include<algorithm>
using namespace std;
long long n,d;
long long a[2000010];
long long l[2000010],r[2000010],top=0;
pair<long long,long long> s[2000010];
long long fl[2000010],fr[2000010];
void func1()
{
    scanf("%lld%lld",&n,&d);
    for(int i=0;i<n;i++)
    {
        l[i]=-1;
        r[i]=n;
        s[i]={0,0};
        fl[i]=0;
        fr[i]=0;
    }
    top=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int j=n;
    for(int i=n-1;i>=0;i--)
    {
        fr[i]=j;
        if(i!=0&&(a[i]-a[i-1])>d)
        {
            j=i;
        }
    }
    j=-1;
    for(int i=0;i<n;i++)
    {
        fl[i]=j;
        if(i!=(n-1)&&(a[i+1]-a[i])>d)
        {
            j=i;
        }
    }
    j=0;
    for(int i=0;i<n;i++)
    {
        while(j<n&&(a[j]-a[i])<=d)
        {
            j++;
        }
        j--;
        l[j]=i;
        r[i]=j;
        if((i>0)&&(i<j)&&(a[j]-a[i-1])<=d)
        {
            s[top++]={i-1,i};
        }
    }
   // for(int i=0;i<n;i++)
   // {
   //     printf("%d %d %d %d\n",s[i].first,s[i].second,l[i],r[i]);
   // }
    j=0;
    long long ans=0,x,y,i;
    for(int j=0;j<top;j++)
    {
        if(j==0)
        {
            x=fl[s[j].second];
        }
        else
        {
            x=l[s[j-1].second];
        }
        if(j==(top-1))
        {
            y=fr[s[j].first];
        }
        else
        {
            y=r[s[j+1].first];
        }
     //   printf("owo %d %d %d %d\n",x,y,l[i],r[i]);
        ans+=max(l[s[j].second]-x,0ll)*max(y-r[s[j].first],0ll);
        j++;

    }
    printf("%lld\n",ans);
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    for(int i=0;i<t;i++)
    {

        func1();

    }
    return 0;
}
