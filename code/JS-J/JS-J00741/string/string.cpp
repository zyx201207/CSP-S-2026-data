#include<bits/stdc++.h>
using namespace std;
int n,s[209178],l=1,r;
char c[209178];
long long sum,minn;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    r=n;
    if(n==1)
    {

        cout << "0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        cin >> c[i];

    }
    while(r>l)
    {
        minn=min(s[r],s[l]);
        if(c[r]==c[l])
        {
            if(minn==s[r]&&minn==s[l])
            {
                r--;
                l++;
            }
            else if(minn==s[r])
            {
                r--;
                s[l]=s[l]-minn;
            }
            else if(minn==s[l])
            {
                l++;
                s[r]=s[r]-minn;
            }
        }
        else
        {
            if(minn==s[r]&&minn==s[l])
            {

                r--;
                l++;
            }
            else if(minn==s[r])
            {

                r--;
                s[l]=s[l]-minn;
            }
            else if(minn==s[l])
            {

                l++;
                s[r]=s[r]-minn;
            }
            sum+=minn;
        }
    }
    cout << sum;

    return 0;
}
