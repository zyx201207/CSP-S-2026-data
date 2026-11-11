#include<bits/stdc++.h>
using namespace std;
struct str{
    long long val;
    char c;
}s[200005];
long long ans;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].val>>s[i].c;
    }
    int left=0,right=n-1;
    while(left<right)
    {
        if(s[left].c==s[right].c)
        {
            if(s[left].val>s[right].val)
            {
                s[left].val-=s[right].val;
                right--;
            }
            else if(s[left].val==s[right].val)
            {
                left++;
                right--;
            }
            else if(s[left].val<s[right].val)
            {
                s[right].val-=s[left].val;
                left++;
            }
        }
        else if(s[left].c!=s[right].c)
        {
            if(s[left].val>s[right].val)
            {
                ans+=s[right].val;
                s[left].val-=s[right].val;
                right--;
            }
            else if(s[left].val==s[right].val)
            {
                ans+=s[left].val;
                left++;
                right--;
            }
            else if(s[left].val<s[right].val)
            {
                ans+=s[left].val;
                s[right].val-=s[left].val;
                left++;
            }
        }
    }
    cout<<ans;
    return 0;
}
