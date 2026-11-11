#include<bits/stdc++.h>
using namespace std;
const long long N=2e6+10;
long long a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long c;
    cin>>c;
    long long t;
    cin>>t;
    long long n,d;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long q=a[2]-a[1];
        long long p=d/q;
        long long o=n-p-2;
        cout<<o+1<<endl;
    }
    return 0;
}
