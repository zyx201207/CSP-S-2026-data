#include<bits/stdc++.h>
using namespace std;
int a[6666],b[8888];
int n,man,man2;
stack<int>l;
stack<int>r;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>man;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=1;i<man;j++)
    {
        man2=0;
        for(int i=j;i<=n;i++)
         {
            r.push(a[i]);
            b[a[i]]++;
            if(b[a[i]!=0)
            {
                 while(!r.empty()&&!l.empty())
                {
                    r.pop();
                }
                r.push(a[i]);
            }

        }
        while(!r.empty())
        {
            man2+=r.top();
            r.pop();
        }
    }
    cout<<man2<<" ";
    return 0;
}
