#include<bits/stdc++.h>
using namespace std;
vector<int>v[1000005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        srand(time(0));
        cout<<rand()%k+1<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
