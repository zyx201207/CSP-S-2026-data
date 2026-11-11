#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],sum[N];
int n,m;
long long mx=0;
int t=0;
int ans=0;
bool tmp=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)tmp=1;
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                mx+=(a[j]-a[j-1])*t;
                ++t;
                if(mx>m){
                    ans=max(ans,j-i);
                    mx=0;
                    t=0;
                    break;
                }
                if(j==n){
                    ans=max(ans,j-i+1);
                    mx=0;
                    t=0;
                    break;
                }
            }
        }
        cout<<ans;
    }
    else if(!tmp){
        for(int i=1;;i++){
            mx+=i;
            if(mx>m){

            cout<<i;
            return 0;
            }
        }
    }
    else{
int cha=a[2]-a[1];
        for(int i=1;;i++){
            mx+=i*cha;
            if(mx>m){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}
