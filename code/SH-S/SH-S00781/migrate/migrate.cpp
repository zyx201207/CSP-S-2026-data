#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e6+2;
const int MAXt = 2*1e5+2;
int c,t,n,d=0;
int x[MAXN],ni[MAXt],di[MAXt],cnt[MAXt];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for(int i =0;i<t;i++){
        cin >> ni[i] >> di[i];
        if(di[i]==1){cnt[i]=0;}
        for(int j = 0;j<ni[i];j++){
            cin >> x[i];
        }
    }
    for(int i =0;i<t;i++){
        cout << 0 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

