#include<bits/stdc++.h>
using namespace std;
long long a[500005],c[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int cs=0,sum=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int zj=n/2+1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[zj]){
           continue;
       }else{
            cs=cs+a[zj]-a[i];
            if(cs<=m) sum+=2;
            else break;
        }
    }
    cout<<sum;
    return 0;
}
