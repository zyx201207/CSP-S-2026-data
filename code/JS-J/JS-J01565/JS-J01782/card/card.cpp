#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
struct node
{
    int num;
    int p;
};
int a[N],ans[M];
int n,m;
int main()
{
   freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        stack<int> st1;vector <int> have;
        for(int j=i;j<=n;j++)
        {
            bool f=0;
            for(int k=0;k<have.size();k++)
            {
                if(have[k]==a[j])
                {
                    f=1;break;
                }
            }
            if(f==0)
            {
                st1.push(a[j]);have.push_back(a[j]);
            }
            else
            {
                while(st1.top()!=a[j])
                {
                    for(int k=0;k<have.size();k++)
                    {
                        if(have[k]==st1.top())
                        {
                            have[k]=0;break;
                        }
                    }
                    st1.pop();
                }
            }

        }
        for(int i=0;i<have.size();i++)
        {
            ans[have[i]]++;
        }

    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}






































