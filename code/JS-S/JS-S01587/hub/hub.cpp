#include<bits/stdc++.h>
using namespace std;
long long m,a[2002000],n,t,c,d,ans,q[2002000],w[2002000],e,r,bl[2002000],bw[2002000];//min w
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","r",stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>ans;
        for(int i=0;i<n;i++)cin>>d;
        cout<<((n+3)/2-ans)/4<<endl;
    }
    return 0;
}
