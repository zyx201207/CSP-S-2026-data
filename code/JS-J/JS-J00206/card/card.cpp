#include<bits/stdc++.h>
using namespace std;
int l[5000],w=0;
int n,m;
int card[5000],ans[2000];
void charge(int x)
{
    for(int i=0;i<=w;i++)
    {
        if(l[i]==x)
        {
            w==i;
        }
    }
}
void play(int x)
{
    for(int i=x-i;i<n;i++)
    {
        charge(card[i]);
        l[w]=card[i];
    }
    for(int i=0;i<=w;i++)
    {
        ans[i]++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>card[i];
    }
    for(int i=1;i<=n;i++)
    {
        play(i);
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i];
    }
    return 0;
}
