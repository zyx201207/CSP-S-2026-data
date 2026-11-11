#include<bits/stdc++.h>
using namespace std;
long long n,m,ans1,sum,cnt,ans,x[500005],j;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    sort(x+1,x+1+n);
    j=n;sum=m;
    for(int i=n;i>=1;i--){
        cnt=x[i];//cout<<x[i]<<" ";
        for(;j>=1;j--){
            if(sum<(cnt-x[j])){
                //cout<<x[j]<<" ";
                ans=max(ans,ans1);
                ans1--;
                sum+=ans1*(x[i]-x[i-1]);
                //cout<<ans1*(x[i]-x[i-1])<<" "<<(x[i]-x[i-1])<<" "<<sum<<"\n";
                break;
            }
            else{
                sum-=(cnt-x[j]);
                ans1++;
            }

        }
        //cout<<"\n";
        ans=max(ans,ans1);
    }
    ans=max(ans,ans1);
    cout<<ans;
    return 0;
}
