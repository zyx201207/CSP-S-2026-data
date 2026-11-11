#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long a[N],t[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cnt=0,mj=0,num=0,ans=0,z=0,d=0,A=0,B=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==i) d++;
    }
    if(d==n){
        for(int i=2;i<=n;i++){
            A+=i;
            if(m<=A){
                cout<<i;
                return 0;
            }
        }
    }
    d=a[2]-a[1];
    A=2;
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]==d) A++;
    }
    if(A==n){
        B=m/d;
        A=0;
        for(int i=2;i<=n;i++){
            A+=i;
            if(B<=A){
                cout<<i;
                return 0;
            }
        }
    }
    cnt=0,mj=m+2,num=0,ans=0,z=0,d=0,A=0,B=0;
    while(mj--){
        for(int i=1;i<=n;i++){
            if(a[i]==a[1]){
                cnt++;
            }
            else break;
        }
        for(int i=1;i<=cnt;i++){
            a[i]++;
        }
        num++;
        if(num==m){
            cout<<cnt;
            return 0;
        }
        cnt=0;
    }
    return 0;
}
