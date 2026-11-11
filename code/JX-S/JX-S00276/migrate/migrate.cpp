#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int a[N],p[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        int n,d;
        cin >> n >> d;
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }
        for(int i=1;i<=n;i++){
            p[i] = a[i]-a[i-1];
        }
        int ans = 0;
        for(int i=d+1;i<=n;i++){
            if(i-1%d != 0){
                if(p[i]>d){
                    ans--;
                }
                ans++;
            }
        }
        cout << ans-1;
    }
    return 0;
}
