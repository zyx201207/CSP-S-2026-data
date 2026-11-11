#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005];
long long anddodo(long long a,long long b){
    long long x=1,y=1,z=1,dx=0,dy=0,dz=0;
    while(a){
        x*=10;
        x+=a%2;
        a/=2;
    }
    while(x){
        dx*=10;
        dx+=x%10;
        x/=10;
    }
    dx/=10;
    while(b){
        y*=10;
        y+=b%2;
        b/=2;
    }
    while(y){
        dy*=10;
        dy+=y%10;
        y/=10;
    }
    dy/=10;
    x=dx;y=dy;
    while(min(x,y)){
        z*=2;
        z+=(int)((x%10)&(y%10));
        x/=10;
        y/=10;
    }
    while(z){
        dz*=2;
        dz+=z%2;
        z/=2;
    }
    dz/=2;
    z=dz;
    return z;
}
int abc(int sum,int gs,int i){
    if(i>n){
        return sum;
    }
    if(sum==0)return max(abc(a[i],gs-1,i+1),abc(0,gs,i+1));
    if(gs>=n-i)return abc(anddodo(sum,a[i]),gs-1,i+1);
    if(gs==0)return abc(sum,gs,i+1);
    return max(abc(anddodo(sum,a[i]),gs-1,i+1),abc(sum,gs,i+1));
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    cout<<abc(0,m,1);
    return 0;
}
