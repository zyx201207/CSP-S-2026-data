#include<algorithm>
#include<iostream>
#include<iterator>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<ctime>
#include<cmath>
#include<set>
#include<map>
using namespace std;

typedef long long ll;

int A,B;
ll n,m,ans;
ll sum[500005];
ll arr[500005];

void solve_usual(){
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(arr[i]*(i-j)-sum[i-1]+sum[j-1]<=m){
                ans=max(ans,ll(i-j+1));
                break;
            }
        }
    }
}

void solve_A(){
    int x,y,k;
    for(int i=1;i<=n;i++){
        x=-2*i+1;
        y=i*i-i-2*m;
        if(x*x-4*y>=0){
            k=ceil(double(-x-sqrt(x*x-4*y))/2.0);
            ans=max(ans,ll(i-max(k,0)));
        }
    }
}

void solve_B(){
    int x,y,z,d,k;
    d=arr[2]-arr[1];
    for(int i=1;i<=n;i++){
        x=d;
        y=-2*i+d;
        z=d*i*i-d*i-2*m;
        if(y*y-4*x*z>=0){
            k=ceil(double(-y-sqrt(y*y-4*x*z))/2.0*x);
            ans=max(ans,ll(i-max(k,0)));
        }
    }
}

void solve_big(){
    sort(arr+1,arr+n+1);
    for(ll l=1,r=1,s=arr[1];l<=r&&r<=n;){
        ans=max(ans,ll(r-l+1));
        if((r-l+1)*arr[r+1]-s<=m){
            r++;
            s+=arr[r];
        }
        else{
            s-=arr[l];
            l++;
        }
        if(l>r){
            r=l;
            s=arr[l];
        }
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",arr+i);
    }
    solve_big();
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
