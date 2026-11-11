#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int n;
ll ans=0;
vector<int>a;
void dfs(int pos,ll sum)

{
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    if(pos==n)
    {
        if(sum<=100)ans=max(ans,sum);
        return;
    }
    dfs(pos+1,sum);
    dfs(pos+1,sum+a[pos]);
}
int main()
{
    cin >>n;
    a.resize(n);
    for(int i=0;i<n;i++)
        dfs(0,0);
    cout <<ans<<endl;
    return 0;
}
