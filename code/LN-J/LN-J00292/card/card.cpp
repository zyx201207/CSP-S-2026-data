#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
char a[MAXN];
int w[MAXN]={0};
string s;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    w[a[n-1]-'0'-1]=n;
    for(int i=0;i<n;i++)
    {
        s="";
        for(int j=i;j<n;j++)
        {
            s+=a[j];
            for(int k=j-1;k>=i;k--)
            {
                if(a[k]==a[j])
                {
                    s.erase(k+1,j);
                }
            }
        }
        for(int j=0;j<m;j++)
        {
            if(s.find(a[j])!=string::npos && j!=a[n-1]-'0'-1)
            {
                w[j]++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        cout<<w[i]<<' ';
    }
    cout<<'\n';
    return 0;
}
