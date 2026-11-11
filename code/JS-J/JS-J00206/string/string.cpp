#include<bits/stdc++.h>
using namespace std;
int n,wei=0;
char a[2000000000];
void paint(int x,char y)
{
    for(int i=0;i<x;i++)
    {
        a[wei+i]=y;
    }
    wei+=x;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        char y;
        cin>>x>>y;
        paint(x,y);
    }
    int ans=0;
    for(int i=0;i<wei/2;i++)
    {
        if(a[i]!=a[wei-i-1]) ans++;
    }
    cout<<ans;
    return 0;
}
