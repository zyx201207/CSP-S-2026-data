#include<bits/stdc++.h>
using namespace std;
int n,x[200010];
char c[200010];
long long ans,cnt;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>c[i];
    int i=1,j=n;
    while(i<=j)
        if(x[i]==x[j]&&c[i]==c[j])i++,j--;
        else if(x[i]==x[j]&&c[i]!=c[j])ans+=x[i++],j--;
        else
        {
            while(x[i]>x[j]&&i<=j)
            {
                if(c[i]!=c[j])ans+=x[j];
                x[i]-=x[j--];
                // cerr<<endl<<"i>j: "<<i<<' '<<j<<' '<<ans<<endl;
            }
            while(x[j]>x[i]&&i<=j)
            {
                if(c[i]!=c[j])ans+=x[i];
                x[j]-=x[i++];
                // cerr<<endl<<"j>i: "<<i<<' '<<j<<' '<<ans<<endl;
            }
        }
    cout<<ans;
}
