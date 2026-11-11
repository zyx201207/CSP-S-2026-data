#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;
    int a=1;
    int t;
    cin>>c;
    cin>>t;
    int n;
    int d;
    int ans=0;
    for(int l=1;l<=t;l++){
        cin>>n;
        cin>>d;
        int x[n+5];
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(x[j]-x[i]==d+d){
                    for(int w=i+1;w<=j;w++){
                        if(x[w]-x[w-1]>=d){
                            a=0;
                        }
                        if(a!=0){
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<ans;
    }
}
