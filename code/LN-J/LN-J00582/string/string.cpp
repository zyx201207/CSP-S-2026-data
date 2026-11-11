#include <bits/stdc++.h>
using namespace std;
long long a[100000002];
string b[10000002];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        for(int j=0;j<a[i];j++)
        {
            s+=b[i];
        }
    }
    int num=0;
    for(int i=0;i<n;i++)
    {
        num+=a[i];
    }
    int step=0;
    if(num%2==1)
    {
        int p=num/2;
        for(int i=p-1;i>=0;i--)
        {

            for(int j=p+1;j<num;j++)
            {
                if(s[i]!=s[j])
                {
                    step++;
                }
            }
        }
        cout<<step/2;
    }
    else{
        int p=num/2;
        for(int i=p-1;i>=0;i--)
        {
            for(int j=p;j<num;j++)
            {
                if(s[i]!=s[j])
                {
                    step++;
                }
            }
        }
        cout<<step/2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
