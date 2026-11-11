#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    for(int q=1;q<=t;q++){
        int n,cnt = 0;
        long long d,a[2000005];
        cin >> n >> d;
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a+1,a+n+1);

        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(a[j] - a[i] <= d) continue;
                int x = i + 1,y = j - 1;
                for(int p=i+1;p<j;p++){
                    if(a[p] - a[i] <= d) x = p;
                    if(a[j] - a[p] <= d) y = p;
                }
                if(y - x + 1 == 2) cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}
