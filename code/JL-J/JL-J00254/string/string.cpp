#include <bnits/stdc++.h>
using namespace std;
int main()
{   freopen("string.in","r",stdin);
    freopen("string.out","w".stdout);
    int a,b[a],c;
    string d[a];
    cin>>a;
    for(int i=1;i<=a;i++)
    {

        cin>>b[i]>>d[i];
    }
    for(int i=1;i<=a;i++)
    {
        for(int j=i+1;j<=a+1;j++)

            if(d[i]==d[j])
        {
            cout<<"0";
            return 0;
        }
    }
    return 0;
}
