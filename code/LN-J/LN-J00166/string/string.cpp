#include<bits/stdc++.h>
using namespace std;
string a;
int sum;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
freopen("string.in","r","std.in");
    freopen("string.out","w","std.out");
    int n;
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        s+=m;
        char b;
        cin>>b;
        for(int j=0;j<m;j++)
        {
            a+=b;
        }
    }
    int s1=s/2;
    for(int i=0;i<s1;i++)
    {
        if(a[i]!=a[s-i-1])
        {
            sum++;
        }
    }
    cout<<sum;
return 0;
}
