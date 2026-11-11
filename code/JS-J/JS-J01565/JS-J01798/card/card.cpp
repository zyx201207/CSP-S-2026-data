#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
int a[N],b[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
    }
    cout<<n<<' '<<m<<' '<<m;
    return 0;
}
