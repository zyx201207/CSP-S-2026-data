#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;

int a[N];

signed main(){
    freopen("and.in","r",stdin);      //Remember change me!!
    freopen("and.out","w",stdout);    //Remember change me!!

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const char endl='\n';

    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    if (m==1){
        int maxx=INT_MIN;
        for (int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout << maxx << endl;
        return 0;
    }
    if (m==2){
        int maxx=INT_MIN;
        for (int i=1;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                int tmp=(a[i]&a[j]);
                maxx=max(maxx,tmp);
            }
        }
        cout << maxx << endl;
        return 0;
    }
    sort(a+1,a+n+1,greater<int>());
    int ans=0;
    for (int i=1;i<=m;i++){
        if (i==1){
            ans=(a[i]&a[i+1]);
            i++;
        }else{
            ans=(ans&a[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
