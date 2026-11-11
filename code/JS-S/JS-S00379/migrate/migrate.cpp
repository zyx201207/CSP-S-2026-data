#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int a[N];
int n,d,cnt;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);   cout.tie(0);
    cin>>c>>t;
    while(t--){
            cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[2]-a[1]>d){
            cout<<0;
            continue;
        }
        int o=a[2]-a[1];
        int ci=d/o;
        if(ci==1){
            cout<<0;
            continue;
        }
        else{
            for(int i=1;i<=n;i++){
                if(i+ci+1<=n)   cnt++;
                }
                cout<<cnt;
            }

        }

    return 0;
}
