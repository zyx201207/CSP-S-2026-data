#include<bits/stdc++.h>
using namespace std;
bool check(string a)
{
    for(int i=0; i<=a.size()/2; i++)
    {
        if(a[i]!=a[a.size()-i-1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string str;
    long long len=0;
    char c;
    for(int i=1; i<=n; i++)
    {
        cin>>len>>c;
        while(len)
        {
            str=str+c;
            len--;
        }
    }

    if(check(str))
    {
        cout<<0;
    }
    else
    {
        //long long mid=str.size()/2;
        long long i=0,j=str.size();
        long long ans;
        while(i>j)
        {
            if(str[i]!=str[j])
            {
                ans++;
            }
            i++;
            j--;
        }
        cout<<ans;
    }


    return 0;
}


