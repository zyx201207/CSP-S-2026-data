#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005],ans,l;
char c[100005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int op=a[i],j=1;
        while(op>0)
        {
            if(c[i]!=c[l-i-j])
            {
                if(op>a[l-i-j])
                {
                    ans+=a[l-i-j];
                    op-=a[l-i-j];
                    a[l-i-j]=0;
                }
                else
                {
                    ans+=op;
                    a[l-i-j]=a[l-i-j]-op;
                    op=0;
                    break;
                }
            }
            else op-=a[l-i-j];
            j++;
        }
    }
    cout<<ans;
    return 0;
}
