#include<queue>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
bool mst;
const int N=5e5+5;
int ans,n,m,a[N];
queue<int> q;
bool med;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1,s=0;i<=n;i++)
    {
        int x=a[i];
        cin>>x,s+=x,q.push(x);
        while(x*(int)q.size()-s>m)
            s-=q.front(),q.pop();
        ans=max(ans,(int)q.size());
    }
    cout<<ans;
    cerr<<(1.0*clock())/CLOCKS_PER_SEC<<endl;
    cerr<<abs(&mst-&med)/1024.0/1024.0<<"MB\n";
}