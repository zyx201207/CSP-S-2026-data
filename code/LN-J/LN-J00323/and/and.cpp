#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[300000],s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int max1[300000],max_i=0;
    for(int i=0;i<300000;i++)
    {
        max1[i]=0;
    }
    //sort(a[1],a[n],a[n]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[j]>=max1[i])
            {
                max1[i]=a[j];
                max_i=j;
            }
        }
        a[max_i]=0;

    }
    s=max1[1];
    cout<<s<<" ";
    for(int i=2;i<=m;i++)
    {
        s=(s&max1[i]);
        cout<<max1[i]<<" ";
    }
    cout<<s;

	return 0;
}




