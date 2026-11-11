#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
int a[N];
int cmp(int x,int y){
    return x<y;
}
long long d[N];
long long sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    d[1]=0;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    //for(int i=2;i<=n;i++){
        //d[i]=a[i]-a[i-1];
    //}
    int cnt=0;
    int l=1;
    for(int r=n;r>=1;){
        if(a[r]<=(sum[r]-sum[l-1]+m)/(r-l+1)){
            cnt=max(cnt,r-l+1);
            r--;
            l=1;
        }
        else l++;

    }
    cout<<cnt;
    return 0;
}

