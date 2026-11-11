#include<bits/stdc++.h>
using namespace std;
long long arr2[100000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long>arr(n);
    for (long long i=0;i<n;i++){
        cin>>arr[i];
    }
    int n2=n-1;
    sort(arr+0,arr+n2);
    long long cnt=0;
    long long dn=0;
    for (long long i=0;i<n;i++){
        for (long long j=i;j>=0;j--){
            long long a=arr[i]-arr[j];
            cnt=cnt+a;
            if (cnt>=m){
                cnt=0;
                break
            }
            arr2[i]++；
            dn=max(arr2[i],dn);
        }
    }
    cout<<dn;
    return 0;
}
