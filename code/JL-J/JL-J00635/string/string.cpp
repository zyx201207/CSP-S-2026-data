#include<bits/stdc++.h>
using namespace std;
int a[100000000];
char b[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    long long d=0;
    for(int i=1;i<=n/2;i++)
    {
        if(b[i]!=b[n-i+1])
        {
            b[n-i+1]=b[i];
            d+=a[n-i+1];
            if(a[i]>a[n-i+1]||a[i]<a[n-i+1])
            {
            d+=abs(a[i]-a[n-i+1]);
            }
        }

    }
    cout<<d;
    return 0;
}
