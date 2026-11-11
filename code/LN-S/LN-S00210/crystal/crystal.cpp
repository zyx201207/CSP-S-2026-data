#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

int n,m;
const int N=5e5+10;

int a[N];
int s[N];
int tail;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    if(n<=1){
        cout << 1 << endl;
        return 0;
    }
    sort(a+1,a+1+n);
    int ans=0;
    int sumtmp=0;
    tail=1;
    for(int i=1;i<=n;i++){
        sumtmp += a[i];
        while(a[i]*(i-tail+1)-(sumtmp)>m){
            sumtmp -= a[tail];
            tail++;
        }
        ans=max(ans,i-tail+1);
    }
    cout << ans << endl;
}