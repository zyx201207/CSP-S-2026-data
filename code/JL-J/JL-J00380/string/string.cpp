#include <bits/stdc++.h>
using namespace std;
int s[200010];
char op[200010][3];
string t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long l=0;
    for (int i=0; i<n; i++)
    {
       cin>>s[i];
       l+=s[i];
       cin>>op[i];
    }
    if (l%2==0)
    {
        long long cnt=0;
        int flag=0;
        long long ans=0;
        for (int i=0; i<n; i++)
        {
            long long si=s[i];
            if (flag==0)
            {
                for (long long j=cnt; j<cnt+si; j++)
                {
                    t+=op[i][0];
                    if (j==l/2-1)
                    {
                        flag=1;
                        break;
                    }
                }
                si=cnt+s[i]-l/2+1;
                cnt=min(cnt+s[i],l/2);
            }
            if (flag==1)
            {
                for (long long j=cnt-1; j>=cnt-si; j--)
                {
                    if (op[i][0]!=t[j])
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
    }
    else
    {
        long long cnt=0;
        int flag=0;
        long long ans=0;
        for (int i=0; i<n; i++)
        {
            long long si=s[i];
            if (flag==0)
            {
                for (long long j=cnt; j<cnt+si; j++)
                {
                    t+=op[i][0];
                    if (j==l/2)
                    {
                        flag=1;
                        break;
                    }
                }
                si=cnt+s[i]-l/2;
                cnt=min(cnt+s[i],l/2+1);
            }
            if (flag==1)
            {
                for (long long j=cnt-1; j>=cnt-si; j--)
                {
                    if (op[i][0]!=t[j])
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
