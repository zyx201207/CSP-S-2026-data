#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2*1e5+10;
LL n,m;
LL a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int ma=0,sum=0,ans=0;
    int ma1=0,x=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];

        if(a[i]>=ma){
            ma=a[i];
        }
    }
    for(int i=0;i<n-1;i++){
        a[i]=a[i] and a[i+1];
        sum=a[i];
        for(int j=i+1;j<n;j++){
            x=a[i] and a[i+1];
            if(x>=ma1){
                ma1=x;
            }
        }
    }
    if(m==1){
        ans=ma;
    }
    if(m==n){
        ans=sum;
    }
    if(m==2){
        ans=ma1;
    }
    cout<<ans;
    return 0;
}
