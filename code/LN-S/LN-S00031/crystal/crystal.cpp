#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5+10;
ll n, m, a[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> n >> m;
    //cout<<"nm"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<"aa"<<endl;
    sort(a,a+n);
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int temp = m;
        //cout<<i<<endl;
        int id = i;
        int cnt = 0;
        while(id >= 0)
        {
            if(a[i] != a[id])
                temp -= a[i]-a[id];
            //cout<<temp<<" "<<id<<endl;
            if(temp < 0)
                break;
            cnt++;
            id--;
        }
        ans = max(ans,cnt);
        //cout<<endl<<ans<<endl<<endl;
    }
    cout<<ans;
    return 0;
}


