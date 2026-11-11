#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 12;
int __,t,n;ll d,a[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>__>>t;
    while(t--){
        memset(a,0,sizeof a);
        cin>>n>>d;
        for(int i = 1;i <= n;i++) cin>>a[i];
        if(n == 1){
            cout<<"0\n";
            continue;
        }
        int d1 = a[2] - a[1];
        int isl = d / d1;
        if(isl < 2){
            cout<<"0\n";
            continue;
        }
        //isl * 2 - 1
        cout<<max(n - isl * 2 + 1,0)<<"\n";
    }
    return 0;
}
