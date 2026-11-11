#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string a;
        cin>>a;

        if(s.find(a)){
            for(int j=s.size()-1;j>=s.find(a);j++)
            {
                s[j]='\0';
            }
            s+=a;
        }
        else s+=a;

        for(int j=1;j<=m;j++)
        {
           if(s.find(j))cnt[j]++;
        }
    }


    for(int i=1;i<=m;i++)
    {
         cout<<cnt[i]<<" ";
    }

    return 0;
}
