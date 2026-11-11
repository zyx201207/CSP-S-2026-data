#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,d[4005];
vector<int>l[4005];
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
        }
        cout<<(n+t+k+c+2)/n<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}