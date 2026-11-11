#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    ios::sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n;
        long long d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i]+d<a[j]){
                        int wa[i+j];
                        int dio=1;
                        for(int l=i+1;l<j;l++){
                                wa[l]=0;
                            while(a[l]<a[j]){
                                a[l]+=d;
                                wa[l]++;
                            }
                        }
                        sort(wa+i+2,wa+j);
                        for(int l=i+2;l<j;l++){
                            if(wa[l]!=wa[i+1]){
                                break;
                            }
                            dio++;
                        }
                        if(dio==2){
                            cnt++;
                        }
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
