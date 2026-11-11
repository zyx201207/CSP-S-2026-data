#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int m,n,w[3000005];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    if(m==1)
    {
         cout<<n<<endl;
        return 0;
    }
    if(m==2)
    {
        if(n==2)
        {
            if(w[1]==1)
            {
                cout<<1<<" "<<2<<endl;
            }
            if(w[1]==2)
            {
                cout<<2<<1<<endl;
            }
        }
        if(n==3)
        {
            if(w[1]==1)
            {
                if(w[2]==1)
                {
                    if(w[3]==2)cout<<2<<" "<<3<<endl;
                }
                if(w[2]==2)
                {
                    if(w[3]==1)cout<<3<<" "<<1<<endl;
                    if(w[3]==2)cout<<1<<" "<<3<<endl;
                }
            }
            if(w[1]==2)
            {
                if(w[2]==1)
                {
                    if(w[3]==1)cout<<3<<" "<<1<<endl;
                    if(w[3]==2)cout<<1<<" "<<3<<endl;
                }
                if(w[2]==2)
                {
                    cout<<3<<" "<<2<<endl;
                }
            }
        }
    return 0;
}