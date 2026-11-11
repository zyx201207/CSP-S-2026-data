#include<bits/stdc++.h>
using namespace std;
char c[10005];
int n,a[10005],ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i]>>c[i];
    for(int i=1;i<=n;i++){
        if(c[i]=c[i+1])
            ans=0;
    }
    if(n==1)ans=0;


    cout<<ans<<endl;
    freopen("string.in","r","in");
    freopen("string.out","w","out");
    return 0;
}
