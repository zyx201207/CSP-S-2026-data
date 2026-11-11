#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,cz,mmax;
bool flag1=1;
long long arr[500002];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>arr[i];
    long long gc=arr[2]-arr[1];
    for(int i=3;i<=n;i++){
        if(arr[i]-arr[i-1]!=gc)flag1=0;
    }
    sort(arr+1,arr+1+n);
    if(flag1){
        long long sum=0;
        cz=m/gc;
        for(int i=1;i<=n-1;i++){
            sum+=i;
            if(sum>cz){
                cout<<i;
                return 0;
            }
        }
        cout<<n;
    }
    for(long long i=1;i<=n;i++){
        cz=m;
        for(long long j=i;j>=1;j--){
            if(cz<arr[i]-arr[j]){
                ans=max(ans,i-j);
                break;
            }
            cz-=arr[i]-arr[j];
            if(j==1)ans=i;
        }
    }
    cout<<ans;
    //gei wo shang mi huo xin wei da shang
    //shang wu ne ge ye shi wo
    //hai xie le hang "gou shi dai ma"(qian qing hui gu)
    //zhun kao zheng hao wang le
    //shang wu mei shi jian xie fei hua
    return 0;
}
