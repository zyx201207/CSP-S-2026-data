#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;
    long long sum=0;
    string s="",v="";
    char c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>c;
        for(int j=1;j<=a;j++) s+=c;
    }
    for(int i=s.length()-1;i>=0;i--) v+=s[i];
    for(int i=0;i<=s.length()-1;i++) if(s[i]!=v[i]) sum++;
    cout<<sum/2;
    return 0;
}
