#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[210000],max1=0,h;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=m;i--)
    {
        h=a[i];
        for(int j=i;j>i-m;j--)h&=a[j];
        if(h>max1)max1=h;
    }
    cout<<max1<<endl;
    return 0;
}
