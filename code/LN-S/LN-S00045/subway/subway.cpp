#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x[500010[,y[500010],a[510[500010],k[500010],w[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >> t[i];
        for(int j=1;j<=t[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int p=1;p<=q;p++){
        cin >>x[p]>>y[p];
        long long ans = 0;
        ans = ans + w[x[p]]+w[y[p]];
        cout << ans << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
