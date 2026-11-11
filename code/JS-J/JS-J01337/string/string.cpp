#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    string b[50005];
    for(int i=0;i<n;i++)
    {
        cin>>a>>b[i];
        if(b[i]==b[i+1])
        {
            cout<<"0";
        }
    }
    return 0;
}

