#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005];
stack<int>st;
map<int,int>mp;
void sv()
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1&&a[i]!=a[i-1])
            cout<<i-1<<' ';
    }
    cout<<n;
    return;
}
void sv1()
{
    int tp=a[n];
    int tp1=tp%2+1;
    b[tp]=n;
    for(int i=1;i<=n;i++)
        if(a[i]==tp1)
            b[tp1]++;
    cout<<b[1]<<' '<<b[2];
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]<a[i-1])
            f=0;
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(m==2)
    {
        sv1();
        return 0;
    }
    if(f)
    {
        sv();
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        mp.clear();
        for(int j=i;j<=n;j++)
        {
            if(mp[a[j]]==0)
            {
                st.push(a[j]);
                mp[a[j]]++;
            }
            else
            {
                while(st.top()!=a[j])
                {
                    mp[st.top()]--;
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            b[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout<<b[i]<<' ';
    return 0;
}
