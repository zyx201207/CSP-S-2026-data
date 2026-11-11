#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

bool flag=1;

long long n;
long long pos=0;
long long ans=0;
long long count=0;

char s[1010100];

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;

    for(int i=0;i<n;i++)
    {
        int a;
        char c;

        cin>>a;
        cin>>c;

        count+=a;

        if(a<pow(10,6))
        {
            for(int j=0;j<a;j++)
            {
                s[pos]=c;
                pos++;
            }
        }
    }

    if(count>pow(10,8))
    {
        cout<<count/2;

        return 0;
    }

    for(int i=0;i<count/2;i++)
    {
        if(s[i]!=s[count-i-1])
        {
            ans++;
        }
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
