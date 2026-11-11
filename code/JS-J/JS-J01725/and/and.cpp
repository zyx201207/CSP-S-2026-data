#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[1000005];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int num=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]>a[j-1])
            {
                num=a[j-1];
                a[j-1]=a[j];
                a[j]=num;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        ans=a[i]&&a[i+1];
    }
    cout<<ans;
    return 0;


}
