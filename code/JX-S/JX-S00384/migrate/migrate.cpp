#include<bits/stdc++.h>
using namespace std;
#define LL long long;
const int N=2e6+500;
int a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        memset(a,0,sizeof(a));
        int sum=0;
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(a[n]-a[1]<=d)cout<<0<<endl;
        else{
            for(int i=1;i<=n;i++){
                for(int j=i+2;j<=n;j++){
                    if(a[j]-a[i]<=d)continue;
                    else{
                        int ans=0;
                        for(int k=i+1;k<j;k++){
                            if(a[k]-a[i]<=d&&a[j]-a[k]<=d)ans++;
                        }
                        if(ans==0){
                            for(int k=i+1;k<j-1;k++){
                                for(int x=k+1;x<j;x++){
                                    if(a[k]-a[i]<=d&&a[x]-a[k]<=d&&a[j]-a[x]<=d){
                                        ans++;
                                    }
                                }
                            }
                            if(ans==2)sum++;
                        }
                        else{
                            if(ans==2)sum++;
                        }
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
