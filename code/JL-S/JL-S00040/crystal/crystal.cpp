#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    int a[500005],b[500005];
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    long long t=0,k=1;
    for(int i=2;i<=m;i++){
        t+=(i-1)*b[i];
        if(t>m){
            t-=i*b[i];
            if((t+a[1])==a[i]){
                k++;
            }
            break;
        }
        k++;
    }
    cout<<k;
    return 0;
}
