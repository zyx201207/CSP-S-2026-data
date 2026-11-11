#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,maxs=1e8+10;
struct node{
    long long num;
    char c;
}a[maxn];
char s[maxs];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int lena=0;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num>>a[i].c;
        lena+=a[i].num;
        if(lena>=1e8) flag=1;
    }
    lena=0;
    if(flag==0)
    {
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i].num;j++)
        {
            lena++;
            s[lena]=a[i].c;
        }
    }
    long long ret=0;
    for(int i=1;i<=lena/2+1;i++)
    {
        if(s[i]!=s[lena-i+1])
        {
            ret++;
        }
    }
    cout<<ret;
    }
    else
    {
        int l=1,r=n;
        long long ret=0;
        while(l<=r)
        {
            int k=a[l].num,t=a[r].num;
            if(a[l].c==a[r].c)
            {
                if(k>t)
                {
                    a[l].num-=a[r].num;
                    r--;
                }
                else if(k==t)
                {
                    l++;r--;
                }
                else if(k<t)
                {
                    a[r].num-=a[l].num;
                    l++;
                }
            }
            else if(a[l].c!=a[r].c)
            {
                if(k>t)
                {
                    a[l].num-=a[r].num;
                    ret+=a[r].num;
                    r--;
                }
                else if(k==t)
                {
                    ret+=a[r].num;
                    l++;r--;
                }
                else if(k<t)
                {
                    ret+=a[l].num;
                    a[r].num-=a[l].num;
                    l++;
                }
            }
        }
        cout<<ret;
    }
    return 0;
}
