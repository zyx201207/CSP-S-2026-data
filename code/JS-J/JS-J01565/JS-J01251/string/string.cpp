#include<bits/stdc++.h>
using namespace std;
long long s[200005];
char s1[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int i = 1;
    while(n--)
    {
        cin>>s[i]>>s1[i];
        if(s1[i] == s1[i-1])
        {
            s[i-1] += s[i];
            s[i] = 0;
            i--;
        }
        i++;
    }
    long long k = 0,l = 1,r = i;
    while(l < r)
    {
        if(s1[l] != s1[r])
        {
            if(s[l] < s[r])
            {
                k += s[l];
            }
            else
            {
                k += s[r];
            }
        }
        if(s[l] > s[r])
        {
            s[l] -= s[r];
            r--;
        }
        else if(s[l] < s[r])
        {
            s[r] -= s[l];
            l++;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout<<k<<'\n';
    return 0;
}
