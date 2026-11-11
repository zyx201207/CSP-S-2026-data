#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        if(n<=d){
            cout<<0;
        }
        long long k=1;
        long long sum=0;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]-a[i-1]>d){
                k=i;
                continue;
            }
            if(a[i-1]-a[k]<=d && a[i]-a[k-1]<=d && a[i]-a[k]>d){
                bool f=0;
                for(long long j=k+1;j<i;j++){
                    if(a[i]-a[j]<=d && a[j]-a[k]<=d){
                        f=1;
                    }
                }
                if(f==0){
                    sum++;
                    k++;
                }
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
