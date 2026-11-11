#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500010],s=0,maxs=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int min=0x7f7f7f7f7,mini;
        s=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i]<min)
            {
                min=a[i];
                mini=i;
            }
        }
        a[mini]++;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==a[mini])
                s++;
        }
        if(maxs<s)
            maxs=s;
    }
    cout<<maxs;
}
