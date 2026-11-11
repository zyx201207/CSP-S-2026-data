#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int m;
    cin>>m;
    vector<int>a(m+1);
    for(int i=1;i<=m;i++)
    {
        char x;
        cin>>a[i]>>x;
        for(int j=1;j<=a[i];j++)s=s+x;
    }
    long long cnt=0;
    long long n=s.size();
    vector<bool>arr(n+1);
    for(long long i=0;i<n&&!arr[i];i++)
    {
        if(s[i]!=s[n-i-1])cnt++;
        arr[i]=1;
        arr[n-i-1]=1;
    }
    cout<<cnt<<'\n';
    return 0;
}
