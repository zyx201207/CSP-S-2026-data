#include<bits/stdc++.h>
#include<stack>
using namespace std;
stack<int> st;
int a[500005],box[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            st.push(a[j]);
            box[a[j]]+=1;
            if(box[a[j]]>=2)
            {
                while(cnt)
                {
                    st.pop();
                    if(st.top()==a[j])
                    {
                        st.pop();
                        cnt=0;
                    }
                }
                st.push(a[j]);
                box[a[j]]=0;
            }
        }
        while(!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
        for(int i=1;i<=m;i++)
        {
            box[i]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
