#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m;
long long a[N],c[N];
long long cnt_A=0,cnt_B=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==i){
            cnt_A++;
        }
    }

    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]==a[i-1]-a[i-2]){
            cnt_B++;
        }
    }
    if(cnt_A==n){
        long long k=0;
        for(int i=1;i<=n;i++){
            k=k+i;
            if(m==k){
                cout<<i+1;
                return 0;
            }
            if(m<k){
                cout<<i;
                return 0;
            }
        }

    }else if(cnt_B==n-2){
        long long k=0;
        long long l=a[2]-a[1];
        for(int i=1;i<=n;i++){
            k=k+i*l;
            if(m==k){
                cout<<i+1;
                return 0;
            }
            if(m<k){
                cout<<i;
                return 0;
            }
        }
    }else if(n<=20){
        long long ans=INT_MIN;
        c[1]=a[1];
        for(int i=2;i<=n;i++){
            c[i]=a[i]-a[i-1];
        }
        for(int i=1;i<=n;i++){
            long long k=0,p=i+1;
            while(m>k&&p<=n){
                k=k+c[p]*(p-1);
                p++;
            }
            ans=max(ans,p-i);
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
