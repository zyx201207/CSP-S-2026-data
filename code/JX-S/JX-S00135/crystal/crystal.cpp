#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5*1e5;
long long a[N];
long long c[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    c[1]=0;
    for(int i=2;i<=n;i++){
        c[i]=(a[1]+a[i-1])*(i-1)/2;
    }
    int idx=upper_bound(c+2,c+n+1,m)-c;
    int xb=idx-1;
    int cnt=0;
    for(int i=xb+1;i<=n;i++){
        if(a[xb]==a[i]){
            cnt++;
        }
        else{
            break;
        }
    }
    cout<<xb+cnt;
    return 0;
}
