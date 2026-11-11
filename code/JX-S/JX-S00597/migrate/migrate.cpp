#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int sum=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                if(a[j]<=a[i]+2*d-1&&a[j]>a[i]+d){
                    sum++;
                }
            }
        }cout<<sum<<endl;
    }
    return 0;
}
