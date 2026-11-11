#include <bits/stdc++.h>
using namespace std;
int a[500005],w[500005];
stack <int>st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.push_back(a[i]);
        if(w[a[i]!=0)
        {
            st.pop()

        }
    }

    for(int i=1;i<=m;i++)
    {
        cout<<1<<" ";
    }
}
