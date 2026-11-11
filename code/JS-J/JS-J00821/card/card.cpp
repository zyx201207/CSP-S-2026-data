#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,s[500005],cnt[300005];
set<ll> st;
vector<ll> q;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int p=1;p<=n;p++)
    {
        st.clear();
        q.clear();
        for(int i=p;i<=n;i++)
        {
            if(st.count(s[i]))
            {
                ll tmp;
                for(int j=0;j<q.size();j++)
                    if(q[j]==s[i])
                    {
                        tmp=j;
                        break;
                    }
                while(q.size()>tmp)
                {
                    st.erase(q[q.size()-1]);
                    q.pop_back();
                }
            }
            q.emplace_back(s[i]);
            st.insert(s[i]);
        }
        for(const auto &y:st)
            cnt[y]++;
    }
    for(int i=1;i<=m;i++)
        cout<<cnt[i]<<' ';
    return 0;
}