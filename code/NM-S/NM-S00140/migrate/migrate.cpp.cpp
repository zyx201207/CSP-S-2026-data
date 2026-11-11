#include <bits/stdc++.h>
using namespace std;
int c,t,sum;
long long n,d;
long long x[100005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    cin>>n>>d;
    for(long long i=1;i<=n;i++){
        cin>>x[i];
        for(long long j=2;j<=n;j++){
            if(x[i]==x[i-1]){
                sum++;
                cout<<sum<<endl;
            }

        }
    }
    return 0;
}
