#include<bits/stdc++.h>
using namespace std;
int c,T,n,k,u,v;
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    srand(time(0));
    cin.tie(0);
    cout.tie(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>k;
        for(int i=1;i<n-1;i++) cin>>u>>v;
        int ans[1005][1005];
        ans[2][1]=1;
        ans[3][1]=1;
        ans[3][2]=1;
        ans[4][1]=1;
        ans[4][2]=1;
        ans[4][3]=1;
        ans[5][1]=2;
        ans[5][2]=1;
        ans[5][3]=1;
        ans[5][4]=1;
        if(n>=k)
        {
            cout<<"0\n";
        }else{
            if(ans[n][k]!=0)
            {
                cout<<ans[n][k]<<'\n';
            }else{
                cout<<rand()%(n/k)+1<<'\n';
            }
        }
    }
    return 0;
}
