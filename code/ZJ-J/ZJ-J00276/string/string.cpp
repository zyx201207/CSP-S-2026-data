#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<char> c(n+1);
    vector<int> sum(n+1);
    for(int i=1;i<=n;++i) 
    {
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
    }
    int len=sum[n];
    int ans=0;
    int id1=1,id2=n;
    int last1=0,last2=0;
    while(id1<id2)
    {  
        int tot=min(sum[id1]-last1,sum[n]-sum[id2-1]-last2);
        last1+=tot;
        last2+=tot;
        if(c[id1]!=c[id2]) ans+=tot;
        if(sum[id1]<sum[n]-sum[id2-1]) id1++;
        else if(sum[id1]>sum[n]-sum[id2-1])id2--;
        else id1++,id2--;
    }
    cout<<ans;
}