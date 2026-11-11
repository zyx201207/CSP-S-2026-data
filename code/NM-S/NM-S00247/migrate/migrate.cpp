#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        int cnt=0;
        bool f[10005];
        for (long long i = 1;i<=n;i++){
            cin >> x[i];
        }
        sort(x+1,x+1+n);
        for (long long i = 2;i<=n;i++){
            if (x[i]-x[i-1]<=d) f[i-1]=1;
            else f[i-1]=0;
        }
        for (int i = 1;i<=n-d-1;i++){
            long long r=0;
            bool h=1;
            for (long long j = i;j<=i+d;j++){
                if (f[j]==1) r++;
                else h=0;
            }
            if(r==3&&h) cnt++;
        }
        cout << cnt << endl;
    }
}
