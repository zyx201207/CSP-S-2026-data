#include<bits/stdc++.h>
using namespace std;
long long n,x,half,ans;
char a;
string st="",ls="",rs="";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>a;
        for(int j=1;j<=x;j++)
            st+=a;
    }
    half=st.size()/2;
    for(int i=0;i<st.size();i++)
    {
        if(i<half)
            ls+=st[i];
        if(i>half)
            rs+=st[i];
    }
    if(rs.size()<half)rs+=st[half];
    for(int i=0;i<=half;i++)
        if(ls[i]!=rs[half-i-1])ans++;
    cout<<ans;
    return 0;
}
