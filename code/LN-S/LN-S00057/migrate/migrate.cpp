#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        int x[n+10];
        int s=0;
        for(int i=1;i<=n;i++){
            cin>>x[i];
            if(x[i]==x[i-1]+1){
                s++;
            }
        }
        if(s==n-1){
            if(n>d*2)cout<<n/(d*2)<<endl;
            else cout<<"0"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
