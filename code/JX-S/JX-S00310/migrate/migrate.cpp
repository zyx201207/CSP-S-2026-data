#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,maxx,cnt=0;
long long a[100000],b[100000];
long long xqw(long long l,long long r,long long z){
    long long mid;
    while(l<=r){
        mid=(l+r)/2;
        if(a[mid]-a[1]<=z&&a[n]-a[mid]<=z){
            break;
        }
        else if(a[mid]-a[1]>z)r--;
        else l++;
    }
    for(int i=1;i<=mid;i++){
        for(int j=mid+1;j<=n;j++){
            if((j-i)/z<=2&&(j-i)%z!=0&&j-i>1)cnt++;
        }
    }
    xqw(l,mid,z/2);
    xqw(mid+1,r,z/2);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cnt=0;
        cin>>n>>d;
        maxx=-10000;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            maxx=max(maxx,a[i]-a[i-1]);
        }
        if(n<=d)cout<<0<<"\n";
        else if(n<2*d){
            cout<<0<<"\n";
        }else if((n-1)/d<=2){
            long long l=1,r=n,mid;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]-a[1]<=d&&a[n]-a[mid]<=d){
                    break;
                }else if(a[mid]-a[1]>d)r--;
                else l++;
            }
            for(int i=1;i<=mid;i++){
                for(int j=mid+1;j<=n;j++){
                    if((j-i)/d<=2&&(j-i)%d!=0&&j-i>1)cnt++;
                }
            }
            cout<<cnt<<"\n";
        }else{
            xqw(1ll,n,(n-1+d-1)/d);
            cout<<cnt<<"\n";
        }
    }
    return 0;
}


