#include <bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    int n,d;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[i];
        }
        int sum=n-d;
        //cout<<sum<<endl;
        if(sum%2!=0){
            cout<<sum/2+1<<endl;
        }else{
            cout<<sum/2<<endl;
        }
    }
    return 0;
}
