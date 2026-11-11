#include<bits/stdc++.h>
using namespace std;
int a[500020],b[300020],c[500020],d[300020],e[500020];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,l=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(b[a[i]]>0)
            {c[l]++;
            c[i]--;}
        b[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        e[i]=e[i-1]+c[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=n;j>=i;j--){
            if(e[j]==0)
            {
                d[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
        cout<<d[i]<<" ";
    return 0;}
