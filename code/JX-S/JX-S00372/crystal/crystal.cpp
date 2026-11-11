#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+15;
long long n,m,a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    b[1]=a[1];
    sort(a,a+n+1);
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    sort(b,b+n+1);
    long long cnt=0,sum=0;
    for(int i=1;i<=n;i++){
        if(b[i+1]<=m&&cnt==0) {
            sum+=b[i+1];
            cnt++;
        }
        else if(sum+b[i+1]<=m){
            cnt++;
            sum+=cnt*b[i+1];
        }
    }
    cout<<cnt<<endl;
    return 0;
}
