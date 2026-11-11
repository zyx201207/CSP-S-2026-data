#include <bits/stdc++.h>
using namespace std;

bool num[500005];
int ans[500005];
int num1[500005];
int ans1[500005];
stack <int> a;
int n,m;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> num1[i];
    for(int j=1;j<=n;j++)
    {
        for(int i=0;i<=300004;i++)
            num[i]=true;
        for(int i=j;i<=n;i++)
        {
            int a1=num1[i];
            if(num[a1])
            {
                a.push(a1);
                num[a1]=false;
            }
            else
            {
                int b=a.top();
                while(b!=a1 && !a.empty())
                {
                    num[b]=true;
                    a.pop();
                    b=a.top();
                }
            }
        }
        while(!a.empty())
        {
            ans1[a.top()]++;
            a.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << ans1[i] << " ";
    }
    return 0;
}
