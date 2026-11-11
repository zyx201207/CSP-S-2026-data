#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,a[500005],cnt[300005],m;
bool flag[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        stack<int>s;
        memset(flag,false,sizeof(flag));
        for(int j=i;j<=n;j++)
        {
           //cout<<a[j];
            if(!flag[a[j]])
            {
                s.push(a[j]);
                flag[a[j]]=true;
            }
            else
            {
                while(s.top()!=a[j])
                {
                    flag[s.top()]=false;
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
/*
4 3
1 2 1 3
*/
