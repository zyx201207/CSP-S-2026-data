#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int s=a[2]-a[1];
        if(s*2<=d&&d<s*3&&n>=3){
            cout<<n-3<<endl;
            continue;
        }else if(s*2>d){
            cout<<0<<endl;
        }else if(s*3<=d&&n>=6){
            cout<<n-5<<endl;
        }else if(n<3){
            cout<<0<<endl;
        }else{
            int q=d/s;
            if(n-2*q+1<0){
                cout<<0<<endl;
            }else{
                cout<<n-2*q+1<<endl;
            }
        }
    }
    return 0;
}
