#include <bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,i,j,a[N],c[500005];
bool t[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    stack<int> st;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<m;j++)
        {
            t[j]=1;
        }
        for(j=i;j<n;j++)
        {
            if(t[c[j]-1])
            {
                t[c[j]-1]=0;
            }
            else
            {
                t[c[j]-1]=1;
                while(st.top()!=c[i])
                {
                    st.pop();
                }
                st.pop();
            }
            st.push(c[j]);
        }
        while(!st.empty())
        {
            a[st.top()-1]++;
            st.pop();
        }
    }
    for(i=0;i<m;i++)
    {
        cout<<a[i]<<' ';
    }
    return 0;
}
