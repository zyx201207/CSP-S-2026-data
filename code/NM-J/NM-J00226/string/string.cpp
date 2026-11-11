#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,b[0];
    char c[0];
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=2*n;i++)
    {
        cin>>b[i]>>c[i];
        c[i]*=b[i];
    }
    cout<<"*O*"
}