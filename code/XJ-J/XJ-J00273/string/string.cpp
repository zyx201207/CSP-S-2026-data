#include <iostream>
#include <cstdio>
using namespace std;
const int N=2e5+10;
int a[N],n,p1,p2;
char c[N];
long long int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i] >> c[i];
    p1=1,p2=n;
    while (p1 < p2){
        if (c[p1] != c[p2]){
            int k=min(a[p1],a[p2]);
            if (a[p1] > a[p2]){
                p2--;a[p1]-=k;
                ans+=k;
            }
            else{
                p1++;
                a[p2]-=k;
                ans+=k;
            }
        }
        else{
            if (a[p1] > a[p2]){
                p2--;
                a[p1]-=a[p2+1];
            }
            else{
                p1++;
                a[p2]-=a[p1-1];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
