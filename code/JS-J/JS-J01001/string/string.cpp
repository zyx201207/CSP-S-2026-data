#include<iostream>
#include<cmath>

using namespace std;

const int MAXN=200070;
long long lft=1,t_len,cnt;
int n;
int lft_p=1,rht_p;
struct str
{
    long long len,lst,cpl;//length,last,how many completed
    char c;
}s[MAXN];


int main()
{
    ios::sync_with_stdio(1);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    rht_p=n;
    for (int i = 1; i <= n; i++)
    {
        cin>>s[i].len>>s[i].c;
        t_len+=s[i].len;
        s[i].lst=t_len;
    }

    while(2*lft < t_len)
    {
        long long rht=t_len+1-lft;
        while(lft>s[lft_p].lst)lft_p++;
        while(rht<=s[rht_p-1].lst)rht_p--;

        int les;
        if(s[lft_p].len-s[lft_p].cpl<s[rht_p].len-s[rht_p].cpl)//left
        {
            les=s[lft_p].len-s[lft_p].cpl;
            s[rht_p].cpl+=les;
        }
        else
        {
            les=s[rht_p].len-s[rht_p].cpl;
            s[lft_p].cpl+=les;
        }
        
        if(s[lft_p].c!=s[rht_p].c)cnt+=les;

        lft+=les;
    }
    
    cout<<cnt;
    
    return 0;
}