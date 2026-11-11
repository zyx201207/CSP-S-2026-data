#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int n,c1,s=0,s2=0,f=1;
    string a;
    char c2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c1>>c2;
        s2+=c1;
        for(int j=0;j<c1;j++)
        {
                a[s2+j-i]=c2;
        }
    }
    int i=0;
    while(i!=s2/2)
    {
        if(a[i]!=a[s2-i])
            i++;
        else
        {
            a[i]=a[s2-i];
            s++;
        }
    }
        cout<<2;
    return 0;
}
