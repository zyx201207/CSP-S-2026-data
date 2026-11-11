#include<bits/stdc++.h>
using namespace std;
struct ges
{
     long long a;
     char c;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,c;
    ges s[200005];
    long long sum=0;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>s[i].a>>s[i].c;
    }
    long long r=n,l=1;
    while(r>l)
    {
        if(s[r].c==s[l].c)
        {
            if(s[r].a>s[l].a)
            {
                s[r].a=s[r].a-s[l].a;
                l++;
            }
            else if(s[r].a==s[l].a)
            {
                l++;
                r--;
            }
            else
            {
                s[l].a=s[l].a-s[r].a;
                r--;
            }
        }
        else
        {
            if(s[r].a>s[l].a)
            {
                sum+=s[l].a;
                s[r].a=s[r].a-s[l].a;
                l++;
            }
            else if(s[r].a==s[l].a)
            {
                sum+=s[l].a;
                l++;
                r--;
            }
            else
            {
                sum+=s[r].a;
                s[l].a=s[l].a-s[r].a;
                r--;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
