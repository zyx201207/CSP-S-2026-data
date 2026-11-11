#include<bits/stdc++.h>
using namespace std;
int c;
long long n,d,t,arr[2000005],k;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(long long i=1;i<=t;i++){
        cin>>n>>d;
        for(long long j=1;j<=n;j++){
            cin>>arr[j];
        }
        k=arr[2]-arr[1];
        if(d/k<=1||n<=3||d>=n){
            if(i==t){
                cout<<0;
            }else{
                cout<<0<<endl;
            }
        }else{
            for(long long j=1;j<=n;j++){
                if(arr[j]>d){
                    cout<<n-j;
                    break;
                }
            }
        }
    }
    return 0;
}
