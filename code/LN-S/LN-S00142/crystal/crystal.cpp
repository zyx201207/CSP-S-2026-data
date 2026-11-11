#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    int f=1;
    for(long long i=1;i<=n;i++){
        if(a[i]!=i){
            f=0;
            break;
        }
    }
    if(f==1){
        long long x=a[n];
        long long sum=0;
        long long cnt=1;
        for(long long i=n-1;i>=1;i--){
            long long t=x-a[i];
            if(sum+t<=m){
                cnt++;
                sum+=t;
            }
        }
        cout<<cnt;
    }else{
        long long ans=0;
        for(long long i=1;i<=n;i++){
            long long x=a[i];
            vector<long long>arr;
            for(long long j=1;j<=n;j++){
                long long t=x-a[j];
                arr.push_back(t);
            }
            sort(arr.begin(),arr.end(),greater<int>());
            long long sum=0;
            long long cnt=0;
            for(long long j=0;j<arr.size();j++){
                if(sum+arr[j]<=m && arr[j]>=0){
                    sum+=arr[j];
                    cnt++;
                }else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        cout<<ans;
    }
    return 0;
}
