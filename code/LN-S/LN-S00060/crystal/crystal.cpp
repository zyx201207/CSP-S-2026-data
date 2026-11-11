#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

long long i,j,k,n,m;
long long a[500005],need[500005];

cin>>n>>m;

for(i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);


for(i=1;i<=n;i++){
    need[i]=a[n]-a[i];
}

long long cost(0),l,r,get;
long long ans(-1);

for(i=2;i<=n;i++){

        cost=0;

    for(j=i-1;j>=1;j--){

        cost+=a[i]-a[j];

        if(cost>m){
            ans=max(ans,i-j);break;
        }

    }

    ans=max(ans,i-j);

}



cout<<ans;













    return 0;
}
