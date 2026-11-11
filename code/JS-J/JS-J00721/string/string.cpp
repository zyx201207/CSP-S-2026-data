#include<bits/stdc++.h>
using namespace std;
const long long M=100000008;
int n,w[M];
long long a,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long k=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        char b;
        cin>>b;
        for (int j=1;j<=a;j++)
        {
            w[++k]=b-'0';
        }
    }
    for (int i=1;i<=k/2;i++)
    {
        long long e=k-i+1;
        if(w[i]!=w[e])
        {
            ans++;
        }
    }
    cout<< ans;
    return 0;
}
