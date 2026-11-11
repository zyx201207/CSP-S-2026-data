#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma,ma1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    ma1=-9999;
    ma=-9999;
    bool A=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma1=max(ma1,a[i]);
        if(a[i]!=i)A=0;
    }
    if(A){
        long long sum=0;
        for(int i=1;i<=ma1;i++){
            sum+=(i-1);
            if(sum<=m){
                ma=i;
            }else{
                break;
            }
        }
        cout<<ma;
        return 0;
    }
    for(int i=1;i<=ma1;i++){
        long long sum=0,shu=0;
        for(int j=1;j<=n;j++){
            if(a[j]<=i){
                sum+=(i-a[j]);
                shu++;
            }
        }
        //cout<<i<<' '<<sum<<' '<<shu<<endl;
        if(sum<=m){
            ma=max(ma,shu);
        }else{
            break;
        }
    }
    cout<<ma;
    return 0;
}
