#include<bits/stdc++.h>
using namespace std;
long long ans,c,n,m,d,q,w[500005],ki,start,endd,a,t;
pair <int,int> atime[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ans = 0;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++){
        cin >> ki;
        for(int j=1;j<=ki;j++)
            cin >> a >> t;
            atime[a].second = t;
    }
    for(int i=1;i<=q;i++)
        cin >> start >> endd;
        cout << w[start]+atime[start].second+atime[endd].second+w[endd] << endl;
    return 0;
}
