#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,a[10000]={0};
        cin>>n>>d;
        for(int i=1;i<n;i++){
            cin>>a[i];
        }
        d=d/(a[2]-a[1]);
        cout<<d*d/2<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
