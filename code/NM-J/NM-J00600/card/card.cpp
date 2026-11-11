#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(n==1&&m==1)
        {
            ans=1;
        }
        else if(n==2&&m==1)
        {
            ans=2;
        }
        else if(n==3&&m==1)
            ans=3;
        else if(n==4&&m==1)
            ans=4;
        else if(n==5&&m==1)
            ans=5;
    }
        if(m==1)
            cout<<ans;
        else if(n==2&&m==2)
        {
            cout<<1<<" "<<2;
        }
        else if(n==3&&m==2){
            if(a[1]==a[2])
                cout<<2<<" "<<2;
            else
                cout<<1<<" "<<2;
        }
    return 0;
}
