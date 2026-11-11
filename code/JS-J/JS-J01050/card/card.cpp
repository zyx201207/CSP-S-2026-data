#include<bits/stdc++.h>
using namespace std;
long long a[100006],b[100006];
bool ch(int k,int g)
{
    for(int i=0;i<=g;i++)
    {
        if(b[i]==k) return 1;
    }
    return 0;
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        memset(b,0,sizeof(b));
        long long s=0;
        for(int j=i;j<=n;j++)
        {
            for(int l=0;l<n-j;l++) b[l] = a[j];
            if(ch(m,j)) s++;
        }
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}
