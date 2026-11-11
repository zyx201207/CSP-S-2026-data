#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,sum = 0,x[2000010];
pair<long long ,long long>path[2000010];
bool mi[2000010] = {1,1};
void minp(int d,int num){
    for(int k = num-1;x[num]-x[k]<=d;k--){
        if(path[num].first != path[k].first+1){
            path[num].first = path[k].first+1;
            path[num].second = 1;
            continue;
        }
        path[num].second++;
        if(path[num].second==2)sum++;
        else if(path[num].second>2)sum--;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        sum = 0;
        cin >> n >> d;
        for(int i = 1;i<=n;i++)cin >> x[i];
        for(int j = 1;j<=n;j++){
            if(x[j]+d>=x[n])break;
            int sta;
            for(int i = j+1;x[i]-x[j]<=d;i++){
                path[i]={1,1};
                sta = i;
            }
            for(int i = sta+1;i<=n;i++){
                minp(d,i);
            }
            for(int i = j+1;i<=n;i++){
                path[i] = {0,0};
            }
        }
        cout << sum << endl;
    }
    return 0;
}
