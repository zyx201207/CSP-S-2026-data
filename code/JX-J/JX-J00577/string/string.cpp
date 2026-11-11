#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",sdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        string c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)
        {
            string s;
            cin>>s;
            s+=c;
        }
    }
    string n=(s.lengh()+1)/2;
    for(int i=0;i<=n.lengh();i++)
    {
        if(n[i]==n[i+1])
        {
            cout<<0;
        }
    }
}
