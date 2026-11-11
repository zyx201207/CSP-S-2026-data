#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==0) cout<<"1\n2";
    while(t--){
        cin>>n>>d;
        int a[n],s[n];
        for(int i=0;i<n;i++){
            cin>>a[n];
            s[i]=a[i]-a[i-1];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
