#include<bits/stdc++.h>
using namespace std;

long long cf2[32]={1,2,4,8,16,
32,64,128,256,512,1024,
2048,4096,8192,16384,32768,65536,
131072,262144,524288,1048576,2097152,
4194304,8388608,16777216,33554432,67108864,
134217728,268435456,536870912,1073741824};
int n,m;
long long a[200005];
int kx[31];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int mac;
    for(mac=1;mac<=30;mac++){
        if(cf2[mac]>=a[n]) break;
    }
    cout<<a[n];
    return 0;
}
