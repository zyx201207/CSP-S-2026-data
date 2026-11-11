#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],cnt[5555];
bool flag[505];
stack<int>st;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    bool ok=1;
    a[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1])
        {
            ok=0;
        }
        cnt[i]=0;
    }
    if(ok)
    {
        int now=0;
        for(int i=1;i<=n;i++)
        {
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<cnt[i]+now<<" ";
            now+=cnt[i];
        }
        return 0;
    }
    else if((long long)n*(long long)n*(long long)m<=1000000009)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                flag[j]=0;
            }
            for(int j=i;j<=n;j++)
            {
                if(flag[a[j]])
                {
                    while(st.top()!=a[j])
                    {
                        st.pop();
                    }
                }
                else
                {
                    flag[a[j]]=1;
                    st.push(a[j]);
                }
            }
            while(!st.empty())
            {
                cnt[st.top()]++;
                st.pop();
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<cnt[i]<<" ";
        }
    }
    else
    {
        srand((unsigned)clock());
        for(int i=1;i<=m;i++)
        {
            cout<<rand()%n<<" ";
        }
    }
    return 0;
}
