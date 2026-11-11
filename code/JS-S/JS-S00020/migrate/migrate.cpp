#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int sum=0;
        for(int i=1;i<n-1;i++){
            if(a[i+1]-a[i-1]<=d){
                sum++;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
