#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,x=-10000;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x=max(x,a[i]);
    }
    if(m==1)
        cout<<x;
    if(m==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=i-1;j<=n;j++)
            {
                x=max(x,a[i]&a[j]);
            }
        cout<<x-3;
    }

	return 0;
}
