#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll d,x[2000050];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t;
    int ans=0;
    cin >> c >> t;
    while(t--){
        ans=0;
        cin >> n >> d;
        for (int i=1;i<=n;i++){
            cin >> x[i];
        }
        x[0]=0;x[n+1]=LONG_LONG_MAX;
        for (int i=1;i<=n;i++){
            for (int j=i;j<=n;j++){
                if (i==j){
                    continue;
                }
                map<int,int> mp;
                mp.clear();
                queue<pair<int,int> > q;
                pair<int,int> tem = {0,i};
                q.push(tem);
                while(!q.empty()){
                    pair<int,int> u = q.front();
                    q.pop();
                    if (u.second==j){
                        mp[u.first]++;
                        continue;
                    }
                    for (int r=u.second+1;r<=j;r++){
                        if (x[r]-x[u.second]>d){
                            break;
                        }
                        pair<int,int> tem2 = {u.first+1,r};
                        q.push(tem2);
                    }
                }
                if (mp.begin()->second==2){
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
