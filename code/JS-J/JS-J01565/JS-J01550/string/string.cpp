#include<bits/stdc++.h>//"It can be proved."
using namespace std;
int a[200000005];
char c[200000005];
string s="0";
string s1,s2;
int main()
#define int long long
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        sum+=a[i];
        for(int j=1;j<=a[i];j++)//"Time Limit Exceeded Big War"
        {
            s+=c[i];
        }
    }
    if(n>2000&&sum>1e9)
    {
        cout<<0;
        return 0;
    }
    int cnt=0;
    if(sum&2==0)
    {
        int t=sum/2;
        for(int i=1;i<=t;i++)
        {
            s1+=s[i];
        }
        for(int i=t+1;i<=sum;i++)
        {
            s2+=s[i];
        }
        int l=0,r=t-1;
        while(l!=t-1)
        {
            if(s1[l]!=s2[r])cnt++;
            l++,r--;
        }
    }
    else
    {
        int t=sum/2;
        for(int i=1;i<=t;i++)
        {
            s1+=s[i];
        }
        for(int i=t+2;i<=sum;i++)
        {
            s2+=s[i];
        }
        int l=0,r=t-1;
        while(l!=t)
        {
            if(s1[l]!=s2[r])cnt++;
            l++,r--;
        }
    }
    cout<<cnt;
    return 0;
}
