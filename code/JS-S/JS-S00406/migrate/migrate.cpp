#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=1e5+1005;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,d,t;
    cin>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>d;
        cout<<n*(n-1)/2<<endl;
    }
    return 0;
}
//please let me pass;
