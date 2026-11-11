#include<bits/stdc++.h>
using namespace std;
long long n,a,h=1,t,len,sum,l[200001];
char c[200001];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>c[i];
        len+=a;
        l[i]=len;
    }
    t=len;
    for (long long i=1;i<=len/2;i++)
    {
        if (t<=h)
            break;
        int nh,nt;
        for (int j=1;j<=n;j++)
        {
            if (l[j]>=h && l[j-1]<h)
            {
                nh=j;
            }
            if (l[j]>=t && l[j-1]<t)
            {
                nt=j;
            }
        }
        if (c[nh]!=c[nt])
        {
            sum++;
        }
        h++;
        t--;
    }
    cout<<sum;
    return 0;
}
