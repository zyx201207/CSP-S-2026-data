#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[500001],b[100001],mxn,x,y,cz[500001],qz[500001];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    stable_sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        x=0,y=0;
        if(a[i]-a[i-1]>=((m+1)/2) and a[i-1]!=a[i-2])continue;
        for(int j=i-1;j>=0;j--){
            if((x+(a[i]-a[j]))>m){
                    y=i-j;
                    break;
            }
            x+=(a[i]-a[j]);

        }
        mxn=max(mxn,y);
    }
    cout<<mxn;
}
