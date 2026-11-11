#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    char cd;
    string h;
    int len=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        cin>>cd;
        for(int j=0;j<a;j++)
        {
            h+=cd;
            len++;
        }

    }
    //cout<<h;
    int num=0;
    for(int i=0;i<len/2;i++)
    {
        if(h[i]!=h[len-i-1])
            num++;
    }
    cout<<num;
    return 0;
}
