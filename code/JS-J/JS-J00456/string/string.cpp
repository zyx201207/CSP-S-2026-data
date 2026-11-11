#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int num;
    char id;
}a[200005];
int n,k;
long long sum,ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].id;
        //cout<<a[i].num<<a[i].id<<"\n";
        sum+=a[i].num;
    }
    long long s=0;
    for(int i=1;i<=n;i++)
    {
        s+=a[i].num;
        if(s*2>=sum)
        {
            k=i;
            break;
        }
    }
    long long s1=a[k].num+sum/2-s,s2=sum/2+s-sum;
    for(int i=k,j=k;i>=1&&j<=n;)
    {
//        cout<<i<<" "<<j<<" "<<s1<<" "<<s2<<"\n";
        int f=a[i].id!=a[j].id;
        if(s1==s2)
        {
            i--,j++;
            ans+=s1*f;
            s1=a[i].num;
            s2=a[j].num;
        }
        else
        if(s1<s2)
        {
            s2-=s1;
            ans+=s1*f;
            i--;
            s1=a[i].num;
        }
        else
        if(s1>s2)
        {
            s1-=s2;
            ans+=s2*f;
            j++;
            s2=a[j].num;
        }
    }
    cout<<ans;
    return 0;
}
