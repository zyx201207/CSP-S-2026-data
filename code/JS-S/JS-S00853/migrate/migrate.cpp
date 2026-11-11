
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t,ans,sum,c;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>m;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            if(m>=2*(a[2]-a[1])&&m<3*(a[2]-a[1])){
                cout<<n-3<<endl;
            }else{
                cout<<0;
            }
    }else{
        for(int i=1;i<=n;i++){
            for(int j=i+2;j<=n;j++){
                    ans=0;
                for(int k=i+1;k<j;k++){
                    if(a[k]-a[i]<=m&&a[j]-a[k]<=m){
                        ans++;
                    }
                }
                if(ans==2){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }

    }
    return 0;
}

