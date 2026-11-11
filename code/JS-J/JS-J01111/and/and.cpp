#include<bits/stdc++.h>
using namespace std;
long long cnt,sum=2147483647;
int n,m;
long long a[200005];
long long p[50]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
map<int,int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=32;i++){
        a[i]=a[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<=32 && a[i]>=p[j];j++){
            if((a[i] & p[j])==p[j]){
                mp[j]++;
            }
        }
    }
    for(int i=32;i>=0;i--){
        if(mp[i]>=m){
            cnt=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if((a[i] & p[cnt])!=p[cnt]){
            a[i]=-1;
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m+1;i--){
        sum=(sum & a[i]);
    }
    cout<<sum;
    return 0;
}
