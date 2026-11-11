#include<bits/stdc++.h>
using namespace std;
int m,n,a[1<<20];
int ans;
int main()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
            cin>>a[i];
    for(int i=1;i<=n;i++)
    {

        if(a[i]<a[i+1])
            ans=1;
    }
    if(ans==1)
    {
        for(int i=1;i<=m;i++)
            a[i]=i;
    }
    for(int i=1;i<=m;i++)
            cout<<a[i]<<" ";
    cout<<endl;
  freopen("card.in","r","in");
  freopen("card.out","w","out");
    return 0;
}
