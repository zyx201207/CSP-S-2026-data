#include <bits/stdc++.h>
using namespace std;
int n,m,x[200005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
    }int cnt=1;int b1=0,b2=0,a1=0,a2=0;
    for(int i=1;i<=n;i++){
        if(x[i]=1){if(b1=0){b1=1;a1++;}else{b1=0;b2=0;}}
        else{if(b2=0){b2=1;a2++;}else{b2=0;b1=0;}}
    }cout<<bi<<" "<<b2;
    return 0;
}
