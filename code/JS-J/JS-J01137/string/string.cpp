#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],q[200005],jzz=1,jrr;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    long long L=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
        q[i]=q[i-1]+a[i];
    }
    jrr=n;
    long long sum=0;
    for(long long i=1;i<=L/2&&jzz<jrr;i+=min(q[jzz]-i+1,L-i+1-q[jrr-1])){
        if(q[jzz]<i){
            jzz++;
        }
        if(q[jrr-1]>=L-i+1){
            jrr--;
        }
        if(c[jzz]!=c[jrr]){
            sum+=min(q[jzz]-i+1,L-i+1-q[jrr-1]);

        }
    }
    cout<<sum;
    return 0;
}
