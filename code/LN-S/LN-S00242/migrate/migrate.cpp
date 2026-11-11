#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;int n,b;
    cin>>c>>t;
    while(t--)
    {

        cin>>n>>b;
        int x[n+1];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int ans=0;
        if(n<3){
            cout<<0<<endl;
            continue;
        }
        else{
            int a=1,c=4;
            while(c<n){
            if(x[c]-x[a]>b&&x[c]-x[c-1]<=b&&x[a+2]-x[a]<=b||x[a+2]-x[a]>b&&x[a+1]-x[a]<=b&&x[c]-x[c-2]<=b){
                a++,c++;
                ans++;
            }
            else{
                a++,c++;
            }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
