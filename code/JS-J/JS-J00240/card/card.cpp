#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[500010];
stack<int> s;
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));
        for(int j=i;j<=n;j++)
        {
            if(!b[a[j]])
            {
                s.push(a[j]);
                b[a[j]]=1;
            }else
            {
                for(int z=j;s.top()!=a[j];z--)
                {
                    s.pop();
                }
            }
        }
        while(!s.empty())
        {
            c[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<c[i]<<" ";
    }
    return 0;
}
