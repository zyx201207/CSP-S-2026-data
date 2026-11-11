#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],b[N],ans;
char c[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        b[i]=a[i]+b[i-1];
    }
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    else if(n==2)
    {
        if(c[1]==c[2])
        {
            cout<<0;
            return 0;
        }
        else if(a[1]<=a[2])
        {
            cout<<a[1];
            return 0;
        }
        else
        {
            cout<<a[2];
            return 0;
        }
    }
    bool flag=0;
    if(b[n]%2==0) flag=1;
    int m,mid=0;
    if(!flag)
    {
        m=b[n]/2+1;
    }
    else m=b[n]/2;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>=m)
        {
            mid=i;
            break;
        }
    }
    int cha=b[mid]-m;
    if(!flag)
    {
        a[mid]=m-b[mid-1]-1-cha;
    }
    else
    {
        a[mid]=m-b[mid-1]-cha;
    }
    int i=mid,j=mid+1;
    while(i>=1&&j<=n)
    {
        while(a[i]<=0)
        {
            int tmp=-a[i];
            if(c[i-1]==c[i])
            {
                if(a[i-1]>tmp)
                {
                    i--;
                    a[i]-=tmp;
                }
                else if(a[i-1]<tmp)
                {
                    i--;
                    tmp-=a[i];
                }
                else
                {
                    i-=2;
                }
            }
            else
            {
                if(a[i-1]>tmp)
                {
                    ans+=tmp;
                    i--;
                    a[i]-=tmp;
                }
                else if(a[i-1]<tmp)
                {
                    ans+=a[i-1];
                    i--;
                    tmp-=a[i];
                }
                else
                {
                    i-=2;
                }
            }
        }
        if(c[i]==c[j])
        {
            if(a[i]>a[j])
            {
                j++;
                a[i]-=a[j];
            }
            else if(a[i]<a[j])
            {
                i--;
                a[j]-=a[i];
            }
            else
            {
                i--;
                j++;
            }
        }
        else
        {

            if(a[i]>a[j])
            {
                ans+=a[j];
                //cout<<ans<<endl;
                j++;
                a[i]-=a[j];
            }
            else if(a[i]<a[j])
            {
                ans+=a[i];
                //cout<<ans<<endl;
                i--;
                a[j]-=a[i];
            }
            else
            {
                ans+=a[i];
                //cout<<ans<<endl;
                i--;
                j++;
            }
        }
    }
    cout<<ans;
    return 0;
}
